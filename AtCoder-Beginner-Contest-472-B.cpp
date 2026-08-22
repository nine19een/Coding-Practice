// Problem:  AtCoder Beginner Contest 472 B - Break a Stick
// Link:     https://atcoder.jp/contests/abc472/tasks/abc472_b
// Author:   nine19een
// Date:     2026-08-22

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;

int n, L[maxn], l, r, ans = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
        r += L[i];
    }
    for (int i = 1; i < n; ++i) {
        l += L[i];
        r -= L[i];
        ans = min(ans, abs(l - r));
    }
    cout << ans;
    return 0;
}
