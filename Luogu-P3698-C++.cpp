// Problem:  Luogu P3698 [CQOI2017] 小Q的棋盘
// Link:     https://www.luogu.com.cn/problem/P3698
// Author:   nine19een
// Date:     2026-03-04

#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9, maxn = 105;

int V, n, dp[maxn][maxn][2];
vector<int> adj[maxn];

void DP(int u, int fa) {
    for (int i = 0; i <= n; i++) {
        dp[u][i][0] = 1;
        dp[u][i][1] = 1;
    }
    if (adj[u].size() == 1 && u) {
        return;
    }
    for (int v: adj[u]) {
        if (v != fa) {
            DP(v, u);
        }
    }
    for (int v: adj[u]) {
        if (v != fa) {
            for (int i = n; i >= 1; --i) {
                for (int j = 1; j <= i; ++j) {
                    dp[u][i][0] = max(dp[v][j - 1][0] + dp[u][i - j][1], dp[u][i][0]);
                    if (j >= 2) {
                        dp[u][i][0] = max(max(dp[v][j - 1][0] + dp[u][i - j][1], dp[v][j - 2][1] + dp[u][i - j][0]),
                                          dp[u][i][0]);
                        dp[u][i][1] = max(dp[v][j - 2][1] + dp[u][i - j][1], dp[u][i][1]);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> n;
    for (int i = 1; i < V; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DP(0, 0);
    cout << dp[0][n][0];
    return 0;
}
