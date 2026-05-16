// Problem:  Luogu P9242 [蓝桥杯 2023 省 B] 接龙数列
// Link:     https://www.luogu.com.cn/problem/P9242
// Author:   nine19een
// Date:     2026-04-08

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, dp[10], tail[maxn], head[maxn], ans;

void DP() {
    for (int i = 1; i <= n; ++i) {
        dp[tail[i]] = max(dp[head[i]] + 1, dp[tail[i]]);
        ans = max(ans, dp[tail[i]]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        head[i] = s.front() - '0';
        tail[i] = s.back() - '0';
    }
    DP();
    cout << n - ans;
    return 0;
}
