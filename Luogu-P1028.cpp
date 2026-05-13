// Problem:  Luogu P1028 [NOIP 2001 普及组] 数的计算
// Link:     https://www.luogu.com.cn/problem/P1028
// Author:   nine19een
// Date:     2025-11-06

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e3 + 5;

int n, dp[maxn];

void DP(int x) {
    int half = x >> 1;
    for (int i = 1; i <= half; i++) {
        if (dp[i] == 1 && i != 1) {
            DP(i);
        }
        dp[x] += dp[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    DP(n);
    cout << dp[n];
    return 0;
}