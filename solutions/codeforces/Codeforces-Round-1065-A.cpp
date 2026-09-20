// Problem:  Codeforces Round 1065 A. Shizuku Hoshikawa and Farm Legs
// Link:     https://codeforces.com/contest/2171/problem/A
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

int t, dp[maxn];

void op() {
    int legs;
    cin >> legs;
    for (int j = 2; j <= 4; j += 2) {
        for (int i = 1; i <= legs; i++) {
            if (i < j) {
                continue;
            }
            dp[i] += dp[i - j];
        }
    }
    cout << dp[legs] << '\n';
    for (int i = 1; i <= legs; ++i) {
        dp[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    dp[0] = 1;
    while (t--) {
        op();
    }
    return 0;
}
