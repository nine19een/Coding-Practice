**中文** / [ENG](README.md)

# Coding Practice

我的竞赛编程与算法练习源码档案，按平台整理在 `solutions/` 下。通过索引查找独立题解及算法变体；刷题和竞赛日志则保留过往记录。

| 导航 | 内容 |
| --- | --- |
| [题目索引](docs/index.md) | 从当前源码生成的导航，包含同题变体 |
| [刷题历史](docs/history/practice.md) | 已冻结的历史练习记录 |
| [竞赛历史](docs/history/contests.md) | 已冻结的历史参赛记录 |

索引统计的是源文件，不代表通过提交数或独立解题数。历史数字与排名按原始记录保留。

## 查找并运行题解

源码分为 `atcoder`、`ccpc`、`codeforces`、`lanqiao`、`luogu`、`misc`、`openjudge` 和 `spoj` 八个目录。每个 `.cpp` 都是有独立输入输出的程序，没有统一应用入口或全仓构建命令。

请按所选文件使用合适的 C++ 编译器。许多题解使用 GCC 特有的 `bits/stdc++.h` 头文件，例如：

```bash
g++ -std=c++17 -O2 solutions/luogu/Luogu-P1001.cpp -o solution
```

运行生成的可执行文件，并提供对应题目的标准输入。这个 A+B 示例输入 `1 2` 时输出 `3`。命令中的 C++17 是示例配置，并非已核实的全仓最低语言标准。

## 添加或更新题解

- 直接放入平台目录，不额外建立比赛文件夹。文件名应能识别题目，例如 `Luogu-P1443.cpp`。
- 同题或同算法重做时，优先更新其规范文件，旧实现由 Git 历史保留。
- 仅为实质不同的算法或数据结构保留平行文件，使用 `-bfs`、`-dfs` 等有含义的后缀。
- 既有历史变体与文件名保持原样。除非属于题目原名，新文件不要添加 `rewrite`、`re`、`redo`、`new`、`v2`、`final` 或 `final2` 后缀。

新题解的头部只需题名和链接：

```cpp
// Luogu P1443 - 马的遍历
// https://www.luogu.com.cn/problem/P1443
```

平行算法变体可补充 `// Method: DFS + DP`。新头部不要求作者与日期；原有历史头部及其来源引用应保留。

## 维护索引

使用 Python 3.10 或更新版本，生成器只依赖标准库：

```bash
python scripts/build_index.py
```

命令读取源码头部并重新生成 `docs/index.md`。题解、生成器、覆盖配置或工作流的相关变更进入 `main` 后，GitHub Actions 会用 Python 3.12 运行生成器，仅在索引变化时提交。不要手工编辑生成索引，也不要继续扩充已冻结的历史表格。

生成器不会丢弃元数据未确认的文件，而是输出警告。[显式元数据覆盖配置](config/problem-overrides.json)记录了六处已核对的头部链接更正和一处题号笔误的来源，不直接修改题解源码。`solutions/misc/` 中两个文件的题目元数据仍未确认。

## 验证范围

一次本地检查在内存中生成了 544 条索引，并与仓库中的索引一致。使用 GCC 13.1.0 编译了 `Luogu-P1001.cpp`、`Luogu-P1443.cpp` 和 `AtCoder-Beginner-Contest-472-A.cpp`，各通过一个小型输入输出检查。这不代表全仓代码均已编译或通过在线评测；仓库没有统一的自动化测试套件。

## 许可

[MIT](LICENSE)，版权所有 © 2025 nine19een。
