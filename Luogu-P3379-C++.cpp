// Problem:  Luogu P3379 【模板】最近公共祖先（LCA）
// Link:     https://www.luogu.com.cn/problem/P3379
// Author:   nine19een
// Date:     2026-01-02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, logn = 25;

int n, m, s, depth[maxn], lca[maxn][logn];
vector<int> adj[maxn];

void DFS(int u, int f) {
    depth[u] = depth[f] + 1;
    lca[u][0] = f;
    for (int k = 1; k < logn; k++) {
        lca[u][k] = lca[lca[u][k - 1]][k - 1];
    }
    for (int v: adj[u]) {
        if (v == f) {
            continue;
        }
        DFS(v, u);
    }
}

int Query(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    for (int k = logn - 1; k >= 0; k--) {
        if (depth[lca[a][k]] >= depth[b]) {
            a = lca[a][k];
        }
    }
    if (a == b) {
        return a;
    }
    for (int k = logn - 1; k >= 0; k--) {
        if (lca[a][k] != lca[b][k]) {
            a = lca[a][k];
            b = lca[b][k];
        }
    }
    return lca[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    DFS(s, 0);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << Query(a, b) << '\n';
    }
    return 0;
}