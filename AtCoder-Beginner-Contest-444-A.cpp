// Problem:  AtCoder Beginner Contest 444 A - Repdigit
// Link:     https://atcoder.jp/contests/abc444/tasks/abc444_a
// Author:   nine19een
// Date:     2026-02-07

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    char c = s.front();
    for (int i = 1; i <= 2; ++i) {
        if (s[i] == c) {
            c = s[i];
        } else {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
