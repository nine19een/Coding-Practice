[中文](README.zh-CN.md) / **ENG**

# Coding Practice

My competitive programming and algorithm practice source archive, organized by platform under `solutions/`. Browse individual solutions and algorithm variants through the index; the practice and contest logs preserve earlier records.

| Where to start | What it contains |
| --- | --- |
| [Problem Index](docs/index.md) | Generated navigation for the current source files, including variants |
| [Practice History](docs/history/practice.md) | Frozen historical practice records |
| [Contest History](docs/history/contests.md) | Frozen historical contest records |

The index counts source files, not accepted submissions or distinct solved problems. Historical figures and rankings remain as originally recorded.

## Browse and run a solution

Sources are grouped into `atcoder`, `ccpc`, `codeforces`, `lanqiao`, `luogu`, `misc`, `openjudge`, and `spoj`. Each `.cpp` file is an independent program with its own input and output; there is no single application to launch or whole-repository build.

Use a suitable C++ compiler for the selected file. Many solutions include the GCC-specific `bits/stdc++.h` header. For example:

```bash
g++ -std=c++17 -O2 solutions/luogu/Luogu-P1001.cpp -o solution
```

Run the resulting executable and provide the problem's standard input. For this A+B example, input `1 2` produces `3`. The C++17 flag is an example configuration, not a verified minimum standard for every archived solution.

## Add or update solutions

- Put files directly in the platform directory; no extra contest folder is needed. Use a self-identifying filename such as `Luogu-P1443.cpp`.
- For an existing problem or a same-algorithm re-solve, update its canonical file. Git preserves previous implementations.
- Keep parallel files for meaningfully different algorithms or data structures, using semantic suffixes such as `-bfs` or `-dfs`.
- Leave existing legacy variants and filenames unchanged. Do not add `rewrite`, `re`, `redo`, `new`, `v2`, `final`, or `final2` suffixes unless they are part of the problem's title.

New solutions need only a title and URL:

```cpp
// Luogu P1443 - 马的遍历
// https://www.luogu.com.cn/problem/P1443
```

Parallel algorithm variants may add `// Method: DFS + DP`. Author and date fields are not required for new headers; preserve historical headers and their source references.

## Maintain the index

Use Python 3.10 or newer; the generator uses only the standard library:

```bash
python scripts/build_index.py
```

This regenerates `docs/index.md` from source headers. After relevant solution, generator, override, or workflow changes reach `main`, GitHub Actions runs it with Python 3.12 and commits the index only if it changed. Do not edit the generated index manually or extend the frozen history tables.

The generator retains files with unresolved metadata and reports warnings. [Explicit metadata overrides](config/problem-overrides.json) correct six audited header URL errors and one problem ID typo without editing solution code; their provenance is recorded in that file. The two files in `solutions/misc/` retain unconfirmed problem metadata.

## Verification scope

A local check generated 544 index entries in memory and matched the tracked index. GCC 13.1.0 compiled `Luogu-P1001.cpp`, `Luogu-P1443.cpp`, and `AtCoder-Beginner-Contest-472-A.cpp`, and each passed a small input/output check. The full archive has not been compiled or judged by this check; there is no repository-wide automated test suite.

## License

[MIT](LICENSE), copyright © 2025 nine19een.
