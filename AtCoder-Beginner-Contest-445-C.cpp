// Problem:  AtCoder Beginner Contest 445 C - Sugoroku Destination
// Link:     https://atcoder.jp/contests/abc443/tasks/abc445_c
// Author:   nine19een
// Date:     2026-02-14

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e5 + 5;

int n, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] == i) {
            continue;
        }
        a[i] = a[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}