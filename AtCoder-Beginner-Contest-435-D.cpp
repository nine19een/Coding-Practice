// Problem:  AtCoder Beginner Contest 435 D - Reachability Query 2
// Link:     https://atcoder.jp/contests/abc435/tasks/abc435_d
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;

struct Node {
    bool isBlack;
    vector<int> adj;
};

int n, m, q;
Node node[maxn];

void dfs(int x) {
    node[x].isBlack = true;
    for (int p: node[x].adj) {
        if (!node[p].isBlack) {
            dfs(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        node[y].adj.push_back(x);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int op, idx;
        cin >> op >> idx;
        if (op == 1 && !node[idx].isBlack) {
            dfs(idx);
        } else if (op == 2) {
            cout << (node[idx].isBlack ? "Yes" : "No") << '\n';
        }
    }
}
