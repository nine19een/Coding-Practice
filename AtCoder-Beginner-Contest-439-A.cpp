// Problem:  AtCoder Beginner Contest 439 A - 2^n - 2*n
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_a
// Author:   nine19een
// Date:     2026-01-04

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 2 * n;
    return 0;
}
