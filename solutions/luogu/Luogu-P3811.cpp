// Problem:  P3811 【模板】模意义下的乘法逆元
// Link:     https://www.luogu.com.cn/problem/P3811
// Author:   nine19een
// Date:     2026-05-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 3e6 + 5;

ll inv[maxn];
int n, p;

void init(const int N, const int MOD) {
    inv[1] = 1;
    for (int i = 2; i <= N; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p;
    int MOD = p, N = n;
    init(N, MOD);
    for (int i = 1; i <= n; ++i) {
        cout << inv[i] << '\n';
    }
    return 0;
}
