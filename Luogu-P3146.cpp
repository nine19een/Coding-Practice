// Problem:  Luogu P3146 [USACO16OPEN] 248 G
// Link:     https://www.luogu.com.cn/problem/P3146
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 260, INF = 1e9;

int n, dp[maxn][maxn], a[maxn], ans;

void Init() {
    for (int i = 1; i <= n; i++) {
        dp[1][i] = a[i];
    }
}

void DP() {
    Init();
    for (int i = 2; i <= n; i++) {
        int const limit = n - i + 1;
        for (int j = 1; j <= limit; j++) {
            for (int k = 1; k <= i - 1; k++) {
                if (dp[k][j] == dp[i - k][j + k] && dp[k][j]) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    DP();
    cout << ans;
    return 0;
}
