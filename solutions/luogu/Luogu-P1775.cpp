// Problem:  Luogu P1775 石子合并（弱化版）
// Link:     https://www.luogu.com.cn/problem/P1775
// Author:   nine19een
// Date:     2026-01-28

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 305, INF = 1e18;

int n, a[maxn], pre[maxn];
ll dp[maxn][maxn];

void DP() {
    for (int i = 2; i <= n; i++) {
        int limit = n - i + 1;
        for (int j = 1; j <= limit; j++) {
            int sum = pre[j + i - 1] - pre[j - 1];
            ll min_dp = INF;
            for (int k = 1; k <= i - 1; k++) {
                min_dp = min(min_dp, dp[k][j] + dp[i - k][j + k] + sum);
            }
            dp[i][j] = min_dp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    DP();
    cout << dp[n][1];
    return 0;
}
