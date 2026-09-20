#!/usr/bin/env python3
"""Build the source index from headers, without editing solutions or using the network."""

import json
import re
import sys
from pathlib import Path
from urllib.parse import quote, urlsplit

ROOT = Path(__file__).resolve().parents[1]
PLATFORMS = {
    "atcoder": "AtCoder", "ccpc": "CCPC / VJudge", "codeforces": "Codeforces",
    "lanqiao": "Lanqiao", "luogu": "Luogu", "misc": "Misc / Unknown",
    "openjudge": "OpenJudge", "spoj": "SPOJ",
}


def warn(path, message):
    print(f"warning: {path}: {message}", file=sys.stderr)


def header_fields(path):
    """Read only initial // comments; support old and lightweight headers."""
    try:
        text = path.read_bytes().decode("utf-8-sig")
    except UnicodeDecodeError:
        warn(path.name, "invalid UTF-8; displaying replacement characters")
        text = path.read_bytes().decode("utf-8", errors="replace")
    comments = []
    for line in text.splitlines():
        if not line.strip():
            continue
        if not line.lstrip().startswith("//"):
            break
        comments.append(line.lstrip()[2:].strip())
    fields = {}
    for line in comments:
        match = re.match(r"(Problem|Link|Author|Date|Method):\s*(.*)", line, re.I)
        if match:
            fields[match[1].lower()] = match[2]
    title = fields.get("problem", "")
    if not title:
        title = next((line for line in comments if line and not re.match(
            r"(?:https?://|(?:Link|Author|Date|Method):)", line, re.I
        )), "")
    links = re.findall(r"https?://[^\s<>]+", fields.get("link", "\n".join(comments)))
    return title, links, fields.get("method", "")


def url_identity(url):
    """Recognize explicit problem URLs; round numbers are not contest IDs."""
    parsed = urlsplit(url)
    host, path = (parsed.hostname or "").removeprefix("www."), parsed.path
    patterns = [
        ("luogu.com.cn", r"/problem/([A-Za-z]+\d+[A-Za-z0-9]*)/?", "luogu"),
        ("atcoder.jp", r"/contests/[^/]+/tasks/([^/]+)/?", "atcoder"),
        ("codeforces.com", r"/(?:contest|gym)/(\d+)/problem/([A-Za-z]\d*)/?", "codeforces"),
        ("codeforces.com", r"/problemset/problem/(\d+)/([A-Za-z]\d*)/?", "codeforces"),
        ("lanqiao.cn", r"/problems/(\d+)(?:/.*)?", "lanqiao"),
        ("vjudge.net", r"/problem/([^/]+)/?", "ccpc"),
        ("spoj.com", r"/problems/([^/]+)/?", "spoj"),
    ]
    for domain, pattern, platform in patterns:
        match = re.fullmatch(pattern, path) if host == domain else None
        if match:
            return platform, "".join(match.groups())
    if host == "openjudge.cn" or host.endswith(".openjudge.cn"):
        match = re.fullmatch(r"/[^/]+/(\d+)/?", path)
        if match:
            return "openjudge", match[1]
    return None


def problem_identity(title):
    for pattern, platform in [
        (r"^Luogu\s+([A-Z]+\d+)\b", "luogu"),
        (r"^opj\s+(\d+)\b", "openjudge"),
        (r"^SP\d+\s+([A-Z][A-Z0-9_]*)\b", "spoj"),
    ]:
        match = re.search(pattern, title, re.I)
        if match:
            return platform, match[1]
    return None


def variant_from(path, method):
    suffix = re.search(r"\(([^()]+)\)$", path.stem)
    if suffix:
        variant = suffix[1]
        if variant == "C":
            variant = "C-style (legacy)"
        elif re.match(r"^(?:rewrite|review|re)(?:-|$)", variant):
            variant = f"legacy: {variant}"
    else:
        # New semantic suffixes, e.g. Luogu-P1443-bfs.
        suffix = re.match(
            r"(?:Luogu-[A-Z]+\d+|opj-\d+|SP-\d+|"
            r"(?:AtCoder|Codeforces).*?-\d+-[A-Z]\d*)-(.+)$", path.stem
        )
        variant = suffix[1] if suffix else ""
    if method and variant.startswith("legacy:"):
        return f"{method}; {variant}"
    return method or variant


def read_entry(path, root, override):
    relative = path.relative_to(root).as_posix()
    title, links, method = header_fields(path)
    title = override.get("title", title)
    if "url" in override:
        links = [override["url"]]
    known = [(url_identity(link), link) for link in links if url_identity(link)]
    declared = problem_identity(title)
    platform, problem_id = known[0][0] if known else (declared or ("misc", "—"))
    url = known[0][1] if known else ""
    if len({identity for identity, _ in known}) > 1:
        warn(relative, "conflicting problem URLs; add an explicit override")
        problem_id, url = "—", ""
    if declared and known and declared != known[0][0]:
        warn(relative, "Problem and URL identities disagree; add an explicit override")
        problem_id, url = "—", ""
    # Explicit Lanqiao-origin headers can link to a Luogu mirror.
    if re.match(r"^(?:蓝桥|【蓝桥|Lanqiao\b)", title, re.I) and platform == "luogu":
        platform, problem_id = "lanqiao", f"{problem_id} (Luogu)"
    platform = override.get("platform", platform)
    problem_id = override.get("problem_id", problem_id)
    if platform not in PLATFORMS:
        raise ValueError(f"{relative}: unsupported platform {platform!r}")
    if not title:
        warn(relative, "missing title; using filename")
        title = path.stem
    if not known:
        warn(relative, "no recognized problem URL; title remains unlinked")
    if problem_id == "—":
        warn(relative, "unconfirmed problem ID/platform; entry retained")
    if path.parent.name != platform:
        warn(relative, f"header platform {platform!r} differs from directory")
    title = re.sub(r"^(?:Luogu\s+[A-Z]+\d+|opj\s+\d+|SP\d+\s+[A-Z0-9_]+)\s*(?:-\s*)?", "", title)
    return {"platform": platform, "id": problem_id, "title": title,
            "url": url, "variant": variant_from(path, method), "path": relative}


def collect_entries(root):
    overrides = json.loads((root / "config/problem-overrides.json").read_text(encoding="utf-8"))["overrides"]
    paths = sorted(root.glob("solutions/**/*.cpp"))
    present = {path.relative_to(root).as_posix() for path in paths}
    for stale in sorted(overrides.keys() - present):
        warn(stale, "override has no matching source")
    entries = [read_entry(path, root, overrides.get(path.relative_to(root).as_posix(), {})) for path in paths]
    return sorted(entries, key=lambda e: (e["platform"], e["id"], e["variant"], e["path"]))


def escape(text):
    return (text.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")
            .replace("\\", "\\\\").replace("|", "&#124;").replace("[", "\\[")
            .replace("]", "\\]").replace("*", "\\*").replace("_", "\\_")
            .replace("`", "\\`").replace("\n", " "))


def render(entries):
    lines = ["# Problem Index", "", "Generated from the current source archive by `scripts/build_index.py`. Do not edit manually.",
             "Each row is one source file; historical variants are retained. This is not an AC count.",
             "Unknown problem metadata is left unconfirmed; original headers are not changed.", ""]
    for platform, label in PLATFORMS.items():
        section = [entry for entry in entries if entry["platform"] == platform]
        if not section:
            continue
        lines += [f"## {label}", "", "| Problem ID | Title | Variant | Code |", "| --- | --- | --- | --- |"]
        for entry in section:
            title = escape(entry["title"])
            if entry["url"]:
                url = quote(entry["url"], safe=":/?=&%#@+~!;,$-_.")
                title = f"[{title}]({url})"
            code = "../" + quote(entry["path"], safe="/")
            lines.append(f"| {escape(entry['id'])} | {title} | {escape(entry['variant']) or '—'} | [Code]({code}) |")
        lines.append("")
    return "\n".join(lines)


def main():
    entries = collect_entries(ROOT)
    output = ROOT / "docs/index.md"
    content = render(entries).encode("utf-8")
    output.parent.mkdir(parents=True, exist_ok=True)
    if not output.exists() or output.read_bytes() != content:
        output.write_bytes(content)
    print(f"Indexed {len(entries)} source files in docs/index.md")


if __name__ == "__main__":
    main()
