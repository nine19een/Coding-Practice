// Problem:  AtCoder Beginner Contest 455 A - 455
// Link:     https://atcoder.jp/contests/abc455/tasks/abc455_a
// Author:   nine19een
// Date:     2026-04-25

#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    if (a != b && b == c) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
