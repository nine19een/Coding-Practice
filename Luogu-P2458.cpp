// Problem:  Luogu P2458 [SDOI2006] 保安站岗
// Link:     https://www.luogu.com.cn/problem/P2458
// Author:   nine19een
// Date:     2026-01-30

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1505, INF = 1e9;

int n, dp[maxn][3], indegree[maxn];
vector<int> adj[maxn];

void DFS(int u) {
    if (adj[u].size() == 0) {
        dp[u][0] = INF;
        return;
    }
    int delta = INF;
    for (int v: adj[u]) {
        DFS(v);
        int base = min(dp[v][0], dp[v][1]);
        dp[u][0] += base;
        dp[u][1] += min(min(dp[v][0], dp[v][1]), min(dp[v][1], dp[v][2]));
        dp[u][2] += min(dp[v][0], dp[v][1]);
        delta = min(delta, dp[v][1] - base);
    }
    dp[u][0] += delta;
}

int find_root() {
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            return i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, m;
        cin >> u >> dp[u][1] >> m;
        for (int j = 1; j <= m; j++) {
            int v;
            cin >> v;
            indegree[v]++;
            adj[u].push_back(v);
        }
    }
    int root = find_root();
    DFS(root);
    cout << min(dp[root][0], dp[root][1]);
    return 0;
}
