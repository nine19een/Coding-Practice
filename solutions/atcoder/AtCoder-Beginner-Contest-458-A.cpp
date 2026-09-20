// Problem:  AtCoder Beginner Contest 458 A - Chompers
// Link:     https://atcoder.jp/contests/abc458/tasks/abc458_a
// Author:   nine19een
// Date:     2026-05-16

#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> n;
    int size = s.length();
    for (int i = n; i < size - n; i++) {
        cout << s[i];
    }
    return 0;
}
