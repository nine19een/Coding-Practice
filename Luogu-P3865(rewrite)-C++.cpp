// Problem:  Luogu P3865 【模板】ST 表 & RMQ 问题
// Link:     https://www.luogu.com.cn/problem/P3865
// Author:   nine19een
// Date:     2026-01-02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, logn = 20;

int n, m, a[maxn], lg2[maxn], st[maxn][logn];

void initLog() {
    lg2[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
}

void buildST() {
    int max_k = lg2[n];
    for (int k = 0; k <= max_k; k++) {
        int max_i = n - (1 << k) + 1;
        for (int i = 1; i <= max_i; i++) {
            st[i][k] = !k ? a[i] : max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int Query(int l, int r) {
    int k = lg2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    initLog();
    buildST();
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << Query(l, r) << '\n';
    }
    return 0;
}
