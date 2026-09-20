// Problem:  AtCoder Beginner Contest 460 B - Two Rings
// Link:     https://atcoder.jp/contests/abc460/tasks/abc460_b
// Author:   nine19een
// Date:     2026-05-30

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ll d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (abs(r1 - r2) * abs(r1 - r2) <= d2 && d2 <= (r1 + r2) * (r1 + r2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
