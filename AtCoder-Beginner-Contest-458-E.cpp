// Problem:  AtCoder Beginner Contest 458 E - Count 123
// Link:     https://atcoder.jp/contests/abc458/tasks/abc458_e
// Author:   nine19een
// Date:     2026-05-16

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxx = 3e6 + 15, MOD = 998244353;

ll x1, x2, x3;
ll fac[maxx], ifac[maxx];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void Init() {
    fac[0] = 1;
    for (int i = 1; i < maxx; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[maxx - 1] = qpow(fac[maxx - 1], MOD - 2);
    for (int i = maxx - 1; i >= 1; i--) {
        ifac[i - 1] = ifac[i] * i % MOD;
    }
}

ll Ans() {
    ll res = 0;
    ll limit = min(x1, x2 + 1);
    for (int i = 1; i <= limit; i++) {
        ll mul = 1;
        mul = mul * C(x2 + 1, i) % MOD;
        mul = mul * C(x1 - 1, i - 1) % MOD;
        mul = mul * C(x2 + x3 - i, x3) % MOD;
        res = (res + mul) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x1 >> x2 >> x3;
    Init();
    cout << Ans();
    return 0;
}
