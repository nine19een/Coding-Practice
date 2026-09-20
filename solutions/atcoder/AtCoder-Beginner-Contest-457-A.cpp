// Problem:  AtCoder Beginner Contest 457 A - Array
// Link:     https://atcoder.jp/contests/abc457/tasks/abc457_a
// Author:   nine19een
// Date:     2026-05-09

#include <bits/stdc++.h>
using namespace std;

int a[105], n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cout << a[x];
    return 0;
}