// Problem:  AtCoder Beginner Contest 460 A - Mod While Positive
// Link:     https://atcoder.jp/contests/abc460/tasks/abc460_a
// Author:   nine19een
// Date:     2026-05-30

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m) {
        m = n % m;
        cnt++;
    }
    cout << cnt;
    return 0;
}
