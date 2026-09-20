// Problem:  P2014 [CTSC1997] 选课
// Link:     https://www.luogu.com.cn/problem/P2014
// Author:   nine19een
// Date:     2026-02-19

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 305;

int n, m, score[maxn], cnt[maxn], dp[maxn][maxn];
vector<int> adj[maxn];

void DP(int u) {
    dp[u][1] = score[u];
    cnt[u] = 1;
    for (int v: adj[u]) {
        DP(v);
        cnt[u] += cnt[v];
        int limit = min(m + 1, cnt[u]);
        for (int i = limit; i > 1; --i) {
            for (int k = 1; k < limit && k < i; ++k) {
                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[v][k]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k >> score[i];
        adj[k].push_back(i);
    }
    DP(0);
    cout << dp[0][m + 1];
    return 0;
}
