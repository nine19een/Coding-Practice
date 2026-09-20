# Coding Practice

My competitive programming and algorithm practice source archive, organized by platform under `solutions/`.
This is a working source archive, not a daily activity log.

- [Problem Index](docs/index.md) — current source files, including variants.
- [Practice History](docs/history/practice.md) — frozen historical timeline.
- [Contest History](docs/history/contests.md) — frozen contest records.

## Adding solutions

Use the platform directory directly; no extra contest folder is needed. Keep new filenames self-identifying, such as `Luogu-P1443.cpp`.
For an existing problem or a same-algorithm re-solve, update its canonical file; Git preserves the previous implementation.
Keep parallel files only for meaningfully different algorithms or data structures, using semantic suffixes such as `-bfs` or `-dfs`.
Existing legacy variants and filenames remain unchanged and are not automatically consolidated.
Do not add `rewrite`, `re`, `redo`, `new`, `v2`, `final`, or `final2` suffixes unless they are part of the problem's title.

New solutions need only a title and URL:

```cpp
// Luogu P1443 - 马的遍历
// https://www.luogu.com.cn/problem/P1443
```

Parallel algorithm variants may add `// Method: DFS + DP`. Author and date fields are not required; leave historical headers as they are.

## Maintenance

Save, commit, and push solutions as usual. After relevant changes reach `main`, GitHub Actions regenerates the [Problem Index](docs/index.md) and commits it only if it changed.
For a local preview, run `python scripts/build_index.py` (Python 3.10+, standard library only).
Do not edit the generated index or extend the frozen history tables.

The generator reads source headers and reports unresolved metadata without dropping files.
[Explicit metadata overrides](config/problem-overrides.json) correct six audited header URL errors and one problem ID typo without editing source code; their provenance is recorded in the configuration.
Files in `solutions/misc/` with unconfirmed platforms remain unconfirmed.
