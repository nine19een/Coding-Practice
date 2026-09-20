// Problem:  2021 CCPC Online H - Subpermutation
// Link:     https://vjudge.net/problem/HDU-7133
// Author:   nine19een
// Date:     2026-07-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7, maxn = 1e6 + 5;

ll t, fac[maxn], ifac[maxn], sum[maxn];

ll qpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[maxn - 1] = qpow(fac[maxn - 1], mod - 2) % mod;
    for (int i = maxn - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    for (int i = 1; i < maxn; ++i) {
        sum[i] = (sum[i - 1] + ifac[i]) % mod;
    }
}

ll ans(int n, int m) {
    return (1ll * n * fac[n - m] % mod - sum[m - 1] % mod + mod) % mod * fac[m] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << ans(n, m) << '\n';
    }
    return 0;
}
