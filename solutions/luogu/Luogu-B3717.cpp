// Problem:  Luogu B3717 组合数问题
// Link:     https://www.luogu.com.cn/problem/B3717
// Author:   nine19een
// Date:     2026-05-17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 5e6 + 5, MOD = 998244353;

int T, N;
ll fac[maxn], ifac[maxn], ans;

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

ll C(ll n, ll m) {
    if (m < 0 || m > n) {
        return 0;
    }
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

void op() {
    ll n, m;
    cin >> n >> m;
    ans ^= C(n, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> N;
    init();
    while (T--) {
        op();
    }
    cout << ans;
    return 0;
}
