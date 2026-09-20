// Problem:  Luogu P12135 [蓝桥杯 2025 省 B] 水质检测
// Link:     https://www.luogu.com.cn/problem/P12135
// Author:   nine19een
// Date:     2026-04-05

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1000005, INF = 1e7;

int l = -1, r = INF, dp[maxn][3];

string s1, s2;

void DP() {
    for (int i = l; i <= r; ++i) {
        int d0 = 2, d1 = 1, d2 = 1;
        if (s1[i] == '#') {
            dp[i][1] = INF;
            d2--;
            d0--;
        }
        if (s2[i] == '#') {
            dp[i][2] = INF;
            d1--;
            d0--;
        }
        if (i == l) {
            dp[i][0] = d0;
            dp[i][1] = d1;
            dp[i][2] = d2;
            continue;
        }
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + d0;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + d1;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][2]) + d2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    int n = s1.length();
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '#' || s2[i] == '#') {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s1[i] == '#' || s2[i] == '#') {
            r = i;
            break;
        }
    }
    if (l == -1 || r == INF || l == r) {
        cout << 0;
        return 0;
    }
    DP();
    cout << min(dp[r][0], min(dp[r][1], dp[r][2]));
    return 0;
}
