// Problem:  AtCoder Beginner Contest 467 C - Adjacent Sums (easy)
// Link:     https://atcoder.jp/contests/abc467/tasks/abc467_c
// Author:   nine19een
// Date:     2026-07-18

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, m, a[maxn], b[maxn], dp[maxn][2];

void DP() {
    dp[0][a[0] ^ 1] = 1;
    for (int i = 1; i < n; ++i) {
        if (b[i] == 1) {
            dp[i][a[i]] = dp[i - 1][a[i] ^ 1];
            dp[i][a[i] ^ 1] = dp[i - 1][a[i]] + 1;
        } else {
            dp[i][a[i]] = dp[i - 1][a[i]];
            dp[i][a[i] ^ 1] = dp[i - 1][a[i] ^ 1] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }
    DP();
    cout << min(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}
