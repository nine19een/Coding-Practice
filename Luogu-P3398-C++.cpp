// Problem:  Luogu P3398 仓鼠找 sugar
// Link:     https://www.luogu.com.cn/problem/P3398
// Author:   nine19een
// Date:     2026-01-03

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, logn = 20;

int n, q, depth[maxn], lca[maxn][logn];
vector<int> adj[maxn];

void DFS(int u, int father) {
    depth[u] = depth[father] + 1;
    lca[u][0] = father;
    for (int i = 1; i <= logn - 1; ++i) {
        lca[u][i] = lca[lca[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != father) {
            DFS(v, u);
        }
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (depth[lca[x][i]] >= depth[y]) {
            x = lca[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

int Distance(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[LCA(x, y)];
}

bool Intersect(int a, int b, int c, int d) {
    int X = LCA(a, b), Y = LCA(c, d);
    return Distance(a, Y) + Distance(b, Y) == Distance(a, b) || Distance(c, X) + Distance(d, X) == Distance(c, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    for (int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (Intersect(a, b, c, d) ? "Y" : "N") << '\n';
    }
    return 0;
}
