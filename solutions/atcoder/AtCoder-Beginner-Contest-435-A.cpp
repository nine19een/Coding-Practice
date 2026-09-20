// Problem:  AtCoder Beginner Contest 435 A - Triangular Number
// Link:     https://atcoder.jp/contests/abc435/tasks/abc435_a
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;

int n, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    cout << sum;
}
