// Problem:  AtCoder Beginner Contest 458 C - C Stands for Center
// Link:     https://atcoder.jp/contests/abc458/tasks/abc458_c
// Author:   nine19een
// Date:     2026-05-16

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll ans;

ll countC(int idx, int len) {
    return min(idx + 1, len - idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'C') {
            ans += countC(i, len);
        }
    }
    cout << ans;
    return 0;
}
