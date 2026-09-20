// Problem:  AtCoder Beginner Contest 438 D - Tail of Snake
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_d
// Author:   nine19een
// Date:     2025-12-30

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;

int n;
ll abc[5][maxn], dp[5][maxn];

ll DP() {
    for (int i = 1; i <= n; ++i) {
        if (i >= 1 && i <= n - 2) {
            dp[1][i] = dp[1][i - 1] + abc[1][i];
        }
        if (i >= 2 && i <= n - 1) {
            dp[2][i] = max(dp[1][i - 1] + abc[2][i], dp[2][i - 1] + abc[2][i]);
        }
        if (i >= 3 && i <= n) {
            dp[3][i] = max(dp[2][i - 1] + abc[3][i], dp[3][i - 1] + abc[3][i]);
        }
    }
    return dp[3][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> abc[i][j];
        }
    }
    cout << DP();
    return 0;
}
