// Problem:  AtCoder Beginner Contest 443 C - Chokutter Addiction
// Link:     https://atcoder.jp/contests/abc438/tasks/abc443_c
// Author:   nine19een
// Date:     2026-01-31

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 3e5 + 5;

int n, t, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a > cur) {
            sum += a - cur;
            cur = a + 100;
        }
    }
    if (t > cur) {
        sum += t - cur;
    }
    cout << sum;
    return 0;
}
