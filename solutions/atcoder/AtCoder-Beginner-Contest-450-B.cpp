// Problem:  AtCoder Beginner Contest 450 B - Split Ticketing
// Link:     https://atcoder.jp/contests/abc450/tasks/abc450_b
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;

int n, c[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            for (int k = i + 1; k < j; ++k) {
                if (c[i][k] + c[k][j] < c[i][j]) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}
