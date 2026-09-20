// Problem:  Luogu P1352 没有上司的舞会
// Link:     https://www.luogu.com.cn/problem/P1352
// Author:   nine19een
// Date:     2026-01-30

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 6005;

int n, r[maxn], dp[maxn][2];
vector<int> adj[maxn];

void DFS(int u, int f) {
    dp[u][1] = r[u];
    for (int v: adj[u]) {
        if (v != f) {
            DFS(v, u);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}
