// Problem:  Luogu P4281 [AHOI2008] 紧急集合 / 聚会
// Link:     https://www.luogu.com.cn/problem/P4281
// Author:   nine19een
// Date:     2026-01-03

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, logn = 20, INF = 0x3f3f3f3f;

struct Ans {
    int idx, a, b, c;
};

int n, m, depth[maxn], lca[maxn][logn];
vector<int> adj[maxn];

void DFS(int u, int father) {
    depth[u] = depth[father] + 1;
    lca[u][0] = father;
    for (int i = 1; i < logn; ++i) {
        lca[u][i] = lca[lca[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != father) {
            DFS(v, u);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (depth[lca[a][i]] >= depth[b]) {
            a = lca[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = logn - 1; i >= 0; --i) {
        if (lca[a][i] != lca[b][i]) {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

int Distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}

Ans Query(int x, int y, int z) {
    vector<Ans> xyz(3);
    xyz[0].idx = LCA(x, y), xyz[1].idx = LCA(y, z), xyz[2].idx = LCA(x, z);
    xyz[0].a = x, xyz[0].b = y, xyz[0].c = z;
    xyz[1].a = y, xyz[1].b = z, xyz[1].c = x;
    xyz[2].a = x, xyz[2].b = z, xyz[2].c = y;
    sort(xyz.begin(), xyz.end(), [](const Ans &p, const Ans &q) {
        return depth[p.idx] > depth[q.idx];
    });
    return xyz.front();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        Ans ans = Query(x, y, z);
        cout << ans.idx << ' ' << Distance(ans.a, ans.b) + Distance(ans.idx, ans.c) << '\n';
    }
    return 0;
}
