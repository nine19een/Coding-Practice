// Problem:  AtCoder Beginner Contest 448 B - Pepper Addiction
// Link:     https://atcoder.jp/contests/abc448/tasks/abc448_b
// Author:   nine19een
// Date:     2026-03-07

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1005;

int n, m, c[maxn], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (c[a] >= b) {
            cnt += b;
            c[a] -= b;
        } else {
            cnt += c[a];
            c[a] = 0;
        }
    }
    cout << cnt;
    return 0;
}
