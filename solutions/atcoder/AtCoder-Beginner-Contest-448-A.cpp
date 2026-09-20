// Problem:  AtCoder Beginner Contest 448 A - chmin
// Link:     https://atcoder.jp/contests/abc448/tasks/abc448_a
// Author:   nine19een
// Date:     2026-03-07

#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a < x) {
            x = a;
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
