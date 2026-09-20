// Problem:  AtCoder Beginner Contest 463 A - 16:9
// Link:     https://atcoder.jp/contests/abc463/tasks/abc463_a
// Author:   nine19een
// Date:     2026-06-20

#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y;
    cout << (x % 16 == 0 && y % 9 == 0 && x / 16 == y / 9 ? "Yes" : "No");
    return 0;
}
