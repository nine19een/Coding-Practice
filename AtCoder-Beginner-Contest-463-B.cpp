// Problem:  AtCoder Beginner Contest 463 B - Train Reservation
// Link:     https://atcoder.jp/contests/abc463/tasks/abc463_b
// Author:   nine19een
// Date:     2026-06-20

#include <bits/stdc++.h>
using namespace std;

int n;
char x;
bool y[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    x -= 'A';
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; ++j) {
            if (s[j] == 'o') {
                y[j] = true;
            }
        }
    }
    cout << (y[int(x)] ? "Yes" : "No");
    return 0;
}
