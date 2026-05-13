// Problem:  Luogu P3155 [CQOI2009] 叶子的染色
// Link:     https://www.luogu.com.cn/problem/P3155
// Author:   nine19een
// Date:     2026-02-23

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5100, maxm = 1e4 + 5;

int m, n, leaf[maxn], dp[maxm][3];
vector<int> adj[maxm];

void DP(int u, int fa) {
    if (adj[u].size() == 1) {
        dp[u][leaf[u]] = 0;
        dp[u][leaf[u] ^ 1] = 1;
        dp[u][2] = 1;
        return;
    }
    int dp0 = 0, dp1 = 0, dp2 = 0;
    for (int v: adj[u]) {
        if (v != fa) {
            DP(v, u);
            dp0 += dp[v][0];
            dp1 += dp[v][1];
            dp2 += dp[v][2];
        }
    }
    dp[u][0] = min(dp0, dp1 + 1);
    dp[u][1] = min(dp1, dp0 + 1);
    dp[u][2] = min(min(dp0 + 1, dp1 + 1), dp2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> leaf[i];
    }
    for (int i = 1; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = n + 1;
    DP(root, 0);
    cout << dp[root][2];
    return 0;
}