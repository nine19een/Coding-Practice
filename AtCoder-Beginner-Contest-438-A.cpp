// Problem:  AtCoder Beginner Contest 438 A - First Contest of the Year
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_a
// Author:   nine19een
// Date:     2025-12-30

#include<bits/stdc++.h>
using namespace std;

int main() {
    int d, f;
    cin >> d >> f;
    cout << (((d - f) / 7) + 1) * 7 + f - d;
    return 0;
}
