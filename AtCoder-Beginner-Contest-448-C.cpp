// Problem:  AtCoder Beginner Contest 448 C - Except and Min
// Link:     https://atcoder.jp/contests/abc443/tasks/abc448_c
// Author:   nine19een
// Date:     2026-03-07

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

int n, q, a[maxn], cpy[maxn];

void op() {
    int k, b[10];
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int idx;
        cin >> idx;
        b[i] = cpy[idx];
    }
    for (int i = 1; i <= n; i++) {
        bool y = true;
        for (int j = 1; j <= k; j++) {
            if (b[j] == a[i]) {
                b[j] = 0;
                y = false;
                break;
            }
        }
        if (y) {
            cout << a[i] << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cpy[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    while (q--) {
        op();
    }
    return 0;
}
