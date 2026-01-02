// Problem:  Luogu P2912 [USACO08OCT] Pasture Walking G
// Link:     https://www.luogu.com.cn/problem/P2912
// Author:   nine19een
// Date:     2026-01-03

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, logn = 11;

struct Node {
    int idx, w;
};

int n, q, depth[maxn], dis[maxn], lca[maxn][logn];
vector<Node> adj[maxn];

void DFS(int u, int dad, int w) {
    depth[u] = depth[dad] + 1;
    dis[u] = dis[dad] + w;
    lca[u][0] = dad;
    for (int i = 1; i < logn; i++) {
        lca[u][i] = lca[lca[u][i - 1]][i - 1];
    }
    for (Node son: adj[u]) {
        int v = son.idx;
        if (v == dad) {
            continue;
        }
        DFS(v, u, son.w);
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    for (int i = logn - 1; i >= 0; i--) {
        if (depth[lca[x][i]] >= depth[y]) {
            x = lca[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = logn - 1; i >= 0; i--) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }
    DFS(1, 0, 0);
    for (int i = 1; i <= q; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        cout << dis[p1] + dis[p2] - 2 * dis[LCA(p1, p2)] << '\n';
    }
    return 0;
}
