// Problem:  AtCoder Beginner Contest 455 D - Card Pile Query
// Link:     https://atcoder.jp/contests/abc455/tasks/abc455_d
// Author:   nine19een
// Date:     2026-04-25

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

int n, q, up[maxn], down[maxn];

int cnt(int x) {
    if (down[x]) {
        return 0;
    }
    int sum = 1, cur = x;
    while (up[cur]) {
        sum++;
        cur = up[cur];
    }
    return sum;
}

void move(int c, int p) {
    up[down[c]] = 0;
    down[c] = p;
    up[p] = c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int c, p;
        cin >> c >> p;
        move(c, p);
    }
    for (int i = 1; i <= n; ++i) {
        cout << cnt(i) << " ";
    }
    return 0;
}
