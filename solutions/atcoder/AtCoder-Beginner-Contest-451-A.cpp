// Problem:  AtCoder Beginner Contest 451 A - illegal
// Link:     https://atcoder.jp/contests/abc451/tasks/abc451_a
// Author:   nine19een
// Date:     2026-03-28

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s.size() % 5) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}
