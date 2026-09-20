// Problem:  Luogu B2164 组合数问题
// Link:     https://www.luogu.com.cn/problem/B2164
// Author:   nine19een
// Date:     2026-05-17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7, maxn = 5005;

ll n, m, fac[maxn], ifac[maxn];

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

ll C(ll a, ll b) {
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    cout << C(n, m);
    return 0;
}
