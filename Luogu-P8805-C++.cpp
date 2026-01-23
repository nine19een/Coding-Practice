// Problem:  Luogu P8805 [蓝桥杯 2022 国 B] 机房
// Link:     https://www.luogu.com.cn/problem/P8805
// Author:   nine19een
// Date:     2026-01-23

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, logn = 20;

int n, m, f[maxn][logn], depth[maxn], delay[maxn], pre[maxn];
vector<int> adj[maxn];

void DFS(int u, int fa, int pre_fa) {
    depth[u] = depth[fa] + 1;
    f[u][0] = fa;
    delay[u] = (int)adj[u].size();
    pre[u] = delay[u] + pre_fa;
    for (int i = 1; i < logn; ++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != fa) {
            DFS(v, u, pre[u]);
        }
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (depth[f[x][i]] >= depth[y]) {
            x = f[x][i];
        }
    }
    if (x == y) {
        return y;
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int Delay(int x, int y) {
    int lca = LCA(x, y);
    return pre[x] + pre[y] - pre[lca] - pre[f[lca][0]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1, 0, 0);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << Delay(u, v) << '\n';
    }
    return 0;
}
