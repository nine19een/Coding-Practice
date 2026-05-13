// Problem:  Luogu P2858 [USACO06FEB] Treats for the Cows G/S
// Link:     https://www.luogu.com.cn/problem/P2858
// Author:   nine19een
// Date:     2026-01-28

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2005;

int n, v[maxn];
ll dp[maxn];

void DP() {
    for (int i = 1; i <= n; i++) {
        int k = n - i + 1;
        for (int j = 1; j <= k; j++) {
            dp[j] = max(dp[j] + v[j + i - 1] * k, dp[j + 1] + v[j] * k);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    DP();
    cout << dp[1];
    return 0;
}