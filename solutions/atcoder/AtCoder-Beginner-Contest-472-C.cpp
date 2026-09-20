// Problem:  AtCoder Beginner Contest 472 C - On a Diet
// Link:     https://atcoder.jp/contests/abc472/tasks/abc472_c
// Author:   nine19een
// Date:     2026-08-22

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 10;

int n, m;
ll k, a[maxn];
bool y[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
        if (sum + a[i] <= k) {
            y[i] = true;
            sum += a[i];
        }
    }
    for (int i = m + 1; i <= n; ++i) {
        if (y[i - m]) {
            sum -= a[i - m];
        }
        if (sum + a[i] <= k) {
            y[i] = true;
            sum += a[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << (y[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}
