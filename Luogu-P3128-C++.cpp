// Problem:  Luogu P3128 [USACO15DEC] Max Flow P
// Link:     https://www.luogu.com.cn/problem/P3128
// Author:   nine19een
// Date:     2026-01-25

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5, logn = 17;

int n, k, f[maxn][logn], depth[maxn], diff[maxn], max_milk;
vector<int> adj[maxn];

void initDFS(int u, int fa) {
    f[u][0] = fa;
    depth[u] = depth[fa] + 1;
    for (int i = 1; i < logn; ++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != fa) {
            initDFS(v, u);
        }
    }
}

int LCA(int s, int t) {
    if (depth[s] < depth[t]) {
        swap(s, t);
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (depth[f[s][i]] >= depth[t]) {
            s = f[s][i];
        }
    }
    if (s == t) {
        return t;
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (f[s][i] != f[t][i]) {
            s = f[s][i];
            t = f[t][i];
        }
    }
    return f[s][0];
}

void Diff(int s, int t) {
    int lca = LCA(s, t);
    diff[s] += 1;
    diff[t] += 1;
    diff[lca] -= 1;
    diff[f[lca][0]] -= 1;
}

void sumDFS(int u, int fa) {
    for (int v: adj[u]) {
        if (v != fa) {
            sumDFS(v, u);
            diff[u] += diff[v];
        }
    }
    max_milk = max(max_milk, diff[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    initDFS(1, 0);
    for (int i = 1; i <= k; i++) {
        int s, t;
        cin >> s >> t;
        Diff(s, t);
    }
    sumDFS(1, 0);
    cout << max_milk;
    return 0;
}
