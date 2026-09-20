// Problem:  AtCoder Beginner Contest 467 B - Keep the Change
// Link:     https://atcoder.jp/contests/abc467/tasks/abc467_b
// Author:   nine19een
// Date:     2026-07-18

#include <bits/stdc++.h>
using namespace std;

int n, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") {
            sum += b - a;
        }
    }
    cout << sum;
    return 0;
}
