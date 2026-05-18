// Problem:  P1641 [SCOI2010] 生成字符串
// Link:     https://www.luogu.com.cn/problem/P1641
// Author:   nine19een
// Date:     2026-05-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2e6 + 10, MOD = 20100403;

int n, m;
ll fac[maxn], ifac[maxn];

ll qpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[maxn - 1] = qpow(fac[maxn - 1], MOD - 2);
    for (int i = maxn - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll N, ll M) {
    if (M < 0 || M > N) {
        return 0;
    }
    return fac[N] * ifac[M] % MOD * ifac[N - M] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    cout << (C(n + m, m) - C(n + m, m - 1) + MOD) % MOD;
    return 0;
}
