// Problem:  Luogu P4071 [SDOI2016] 排列计数
// Link:     https://www.luogu.com.cn/problem/P4071
// Author:   nine19een
// Date:     2026-05-17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7, maxn = 1e6 + 5;

int t;
ll fac[maxn], ifac[maxn], D[maxn];

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
    D[0] = 1;
    D[1] = 0;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[maxn - 1] = qpow(fac[maxn - 1], MOD - 2);
    for (int i = maxn - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
    for (int i = 2; i < maxn; ++i) {
        D[i] = (i - 1) * ((D[i - 1] + D[i - 2]) % MOD) % MOD;
    }
}

ll C(ll n, ll m) {
    if (m < 0 || m > n) {
        return 0;
    }
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

void op() {
    ll n, m;
    cin >> n >> m;
    cout << C(n, m) * D[n - m] % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    init();
    while (t--) {
        op();
    }
    return 0;
}
