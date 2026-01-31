// Problem:  AtCoder Beginner Contest 443 D - Pawn Line
// Link:     https://atcoder.jp/contests/abc443/tasks/abc443_d
// Author:   nine19een
// Date:     2026-01-31

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void op() {
    int n;
    ll sum = 0;
    cin >> n;
    vector<int> r(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    a = r;
    for (int i = 1; i < n; ++i) {
        a[i] = min(a[i], a[i - 1] + 1);
    }
    for (int i = n - 2; i >= 0; --i) {
        a[i] = min(a[i], a[i + 1] + 1);
        sum += r[i] - a[i];
    }
    sum += r[n - 1] - a[n - 1];
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
