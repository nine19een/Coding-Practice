// Problem:  AtCoder Beginner Contest 449 A - π
// Link:     https://atcoder.jp/contests/abc449/tasks/abc449_a
// Author:   nine19een
// Date:     2026-03-14

#include <bits/stdc++.h>
using namespace std;
constexpr double pi = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double d;
    cin >> d;
    cout << fixed << setprecision(15) << (d / 2) * (d / 2) * pi;
    return 0;
}
