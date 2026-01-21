// Problem:  Luogu P1396 营救
// Link:     https://www.luogu.com.cn/problem/P1396
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

struct Edge {
    int v, w;
};

int n, m, s, t, max_w;
vector<Edge> area[maxn];
bool vis[maxn];

bool DFS(int x, int u) {
    if (u == t) {
        return true;
    }
    vis[u] = true;
    for (const Edge &e: area[u]) {
        if (e.w <= x && !vis[e.v]) {
            if (DFS(x, e.v)) {
                return true;
            }
        }
    }
    return false;
}

int Binary() {
    int l = 0, r = max_w + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (DFS(mid, s)) {
            r = mid;
        } else {
            l = mid + 1;
        }
        memset(vis, false, sizeof vis);
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        max_w = max(max_w, w);
        area[u].push_back({v, w});
        area[v].push_back({u, w});
    }
    cout << Binary();
    return 0;
}
