// Problem:  AtCoder Beginner Contest 472 A - A
// Link:     https://atcoder.jp/contests/abc472/tasks/abc472_a
// Author:   nine19een
// Date:     2026-08-22

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (char c: s) {
        if (c == 'A') {
            cout << c;
        } else {
            cout << '.';
        }
    }
    return 0;
}
