// Problem:  AtCoder Beginner Contest 445 B - Center Alignment
// Link:     https://atcoder.jp/contests/abc443/tasks/abc445_b
// Author:   nine19een
// Date:     2026-02-14

#include <bits/stdc++.h>
using namespace std;

int n, max_len;
vector<string> s;

void print_dot(int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        cout << ".";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.push_back(str);
        max_len = max((int) str.length(), max_len);
    }
    for (string &str: s) {
        int cnt_dot = (max_len - str.length()) / 2;
        print_dot(cnt_dot);
        cout << str;
        print_dot(cnt_dot);
        cout << '\n';
    }
    return 0;
}
