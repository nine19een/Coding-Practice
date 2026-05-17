// Problem:  Luogu P2265 路边的水沟
// Link:     https://www.luogu.com.cn/problem/P2265
// Author:   nine19een
// Date:     2026-05-17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxtot = 2e6 + 10, MOD = 1000000007;

ll N, M, fac[maxtot], ifac[maxtot];

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
    for (int i = 1; i < maxtot; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[maxtot - 1] = qpow(fac[maxtot - 1], MOD - 2);
    for (int i = maxtot - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll n, ll m) {
    if (m < 0 || m > n) {
        return 0;
    }
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    init();
    cout << C(M + N, min(M, N));
    return 0;
}
