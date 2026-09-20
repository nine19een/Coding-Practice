// Problem:  P1313 [NOIP 2011 提高组] 计算系数
// Link:     https://www.luogu.com.cn/problem/P1313
// Author:   nine19een
// Date:     2026-05-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 10007, maxn = 1005;

ll a, b, k, n, m, fac[maxn], ifac[maxn], ab;

ll qpow(ll x, ll p) {
    ll res = 1;
    x %= MOD;
    while (p) {
        if (p & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        p >>= 1;
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

ll C(ll K, ll N) {
    return fac[K] * ifac[N] % MOD * ifac[K - N] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> k >> n >> m;
    init();
    cout << qpow(a, n) * qpow(b, m) % MOD * C(k, n) % MOD;
    return 0;
}
