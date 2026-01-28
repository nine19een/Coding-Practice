// Problem:  Luogu P1622 释放囚犯
// Link:     https://www.luogu.com.cn/problem/P1622
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
constexpr int maxq = 105, INF = 1e9;

int n, q, a[maxq], dp[maxq][maxq];

void DP() {
    for (int i = 2; i <= q + 1; ++i) {
        for (int idx = 0; idx <= q + 1 - i; ++idx) {
            int j = idx + i;
            int min_val = INF;
            int range_sum = a[j] - a[idx] - 2;
            for (int k = 1; k < i; ++k) {
                min_val = min(min_val, dp[idx][idx + k] + dp[idx + k][j] + range_sum);
            }
            dp[idx][idx + i] = min_val;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i];
    }
    a[0] = 0, a[q + 1] = n + 1;
    DP();
    cout << dp[0][q + 1];
    return 0;
}
