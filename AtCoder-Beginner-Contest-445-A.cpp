// Problem:  AtCoder Beginner Contest 445 A - Strong Word
// Link:     https://atcoder.jp/contests/abc443/tasks/abc445_a
// Author:   nine19een
// Date:     2026-02-14

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    if (s.front() == s.back()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
