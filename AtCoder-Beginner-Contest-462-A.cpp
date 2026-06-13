// Problem:  AtCoder Beginner Contest 462 A - Secret Numbers
// Link:     https://atcoder.jp/contests/abc462/tasks/abc462_a
// Author:   nine19een
// Date:     2026-06-13

#include <bits/stdc++.h>
using namespace std;

string s, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (char c: s) {
        if (c >= '0' && c <= '9') {
            ans += c;
        }
    }
    cout << ans;
    return 0;
}
