// Problem:  Luogu P3258 [JLOI2014] 松鼠的新家
// Link:     https://www.luogu.com.cn/problem/P3258
// Author:   nine19een
// Date:     2026-01-23

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, logn = 20;

int n, a[maxn], depth[maxn], f[maxn][logn], diff[maxn];
vector<int> adj[maxn];

void initDFS(int u, int fa) {
    depth[u] = depth[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < logn; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != fa) {
            initDFS(v, u);
        }
    }
}

int Lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    for (int i = logn - 1; i >= 0; i--) {
        if (depth[f[x][i]] >= depth[y]) {
            x = f[x][i];
        }
    }
    if (x == y) {
        return y;
    }
    for (int i = logn - 1; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

void Diff(int x, int y) {
    int lca = Lca(x, y);
    diff[x]++;
    diff[y]++;
    diff[lca]--;
    diff[f[lca][0]]--;
}

void sumDFS(int u, int fa) {
    for (int v: adj[u]) {
        if (v != fa) {
            sumDFS(v, u);
            diff[u] += diff[v];
        }
    }
}

void cntCandy() {
    for (int i = 2; i <= n; i++) {
        Diff(a[i - 1], a[i]);
        if (i != 2) {
            diff[a[i - 1]]--;
            diff[f[a[i - 1]][0]]++;
        }
        if (i == n) {
            diff[a[i]]--;
            diff[f[a[i]][0]]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    initDFS(1, 0);
    cntCandy();
    sumDFS(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << diff[i] << '\n';
    }
    return 0;
}
