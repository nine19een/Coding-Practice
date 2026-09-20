// Problem:  Luogu P9245 [蓝桥杯 2023 省 B] 景区导游
// Link:     https://www.luogu.com.cn/problem/P9245
// Author:   nine19een
// Date:     2026-01-23

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5, logn = 20;

struct Edge {
    int v;
    ll t;
};

int n, k, a[maxn], f[maxn][logn], depth[maxn];
ll pre[maxn], tot_dis;
vector<Edge> adj[maxn];

void DFS(int u, int fa, ll fa_t) {
    depth[u] = depth[fa] + 1;
    f[u][0] = fa;
    pre[u] = pre[f[u][0]] + fa_t;
    for (int i = 1; i < logn; ++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (Edge e: adj[u]) {
        if (e.v != fa) {
            DFS(e.v, u, e.t);
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

ll Distance(int x, int y) {
    return pre[x] + pre[y] - 2 * pre[LCA(x, y)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    DFS(1, 0, 0);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        if (i > 1) {
            tot_dis += Distance(a[i], a[i - 1]);
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (i == 1) {
            cout << tot_dis - Distance(a[1], a[2]) << " ";
        } else if (i == k) {
            cout << tot_dis - Distance(a[k], a[k - 1]);
        } else {
            cout << tot_dis - Distance(a[i], a[i - 1]) - Distance(a[i], a[i + 1]) + Distance(a[i - 1], a[i + 1]) << " ";
        }
    }
    return 0;
}