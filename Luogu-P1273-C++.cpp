// Problem:  P1273 有线电视网
// Link:     https://www.luogu.com.cn/problem/P1273
// Author:   nine19een
// Date:     2026-02-19

#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9, maxn = 3005;

int n, m, cost[maxn], money[maxn], cnt[maxn], dp[maxn][maxn];
vector<int> adj[maxn];

void init_dp() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }
}

void DP(int u) {
    dp[u][0] = 0;
    if (adj[u].empty()) {
        cnt[u] = 1;
        dp[u][1] = money[u] - cost[u];
        return;
    }
    for (int v: adj[u]) {
        DP(v);
        for (int i = cnt[u] + cnt[v]; i >= 1; i--) {
            for (int k = max(1, i - cnt[u]); k <= cnt[v]; k++) {
                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[v][k]);
            }
        }
        cnt[u] += cnt[v];
    }
    for (int i = 1; i <= cnt[u]; i++) {
        dp[u][i] -= cost[u];
    }
}

int ANS() {
    int ans = 0;
    for (int i = 1; i <= cnt[1]; i++) {
        if (dp[1][i] >= 0) {
            ans = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n - m; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int node_num;
            cin >> node_num;
            cin >> cost[node_num];
            adj[i].push_back(node_num);
        }
    }
    for (int i = n - m + 1; i <= n; ++i) {
        cin >> money[i];
    }
    init_dp();
    DP(1);
    cout << ANS();
    return 0;
}
