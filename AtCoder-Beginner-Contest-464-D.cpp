// Problem:  AtCoder Beginner Contest 464 D - Celester
// Link:     https://atcoder.jp/contests/abc464/tasks/abc464_d
// Author:   nine19een
// Date:     2026-06-27

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

int t;
ll x[maxn], y[maxn], dp[maxn][2];

void DP(int n, const string &s) {
    dp[1][0] = s[0] == 'R' ? 0 : -x[1];
    dp[1][1] = s[0] == 'S' ? 0 : -x[1];
    for (int i = 2; i <= n; ++i) {
        int si = i - 1;
        ll dr = s[si] == 'R' ? 0 : -x[i];
        ll ds = s[si] == 'S' ? 0 : -x[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + dr;
        dp[i][1] = max(dp[i - 1][0] + y[si], dp[i - 1][1]) + ds;
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> y[i];
    }
    DP(n, s);
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
