// Problem:  AtCoder Beginner Contest 459 E - Select from Subtrees
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_e
// Author:   nine19een
// Date:     2026-05-24

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2e5 + 5, maxd = 1e6 + 5, MOD = 998244353;

ll n, fac[maxd], ifac[maxd], c[maxn], d[maxn];
bool noAns;
vector<int> adj[maxn];
vector<pair<ll, ll> > allC;

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
    for (int i = 1; i < maxd; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[maxd - 1] = qpow(fac[maxd - 1], MOD - 2);
    for (int i = maxd - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
}

void DP(int u, int f) {
    for (int v: adj[u]) {
        if (v != f) {
            DP(v, u);
            if (noAns) {
                return;
            }
            c[u] += c[v] - d[v];
        }
    }
    if (c[u] < d[u]) {
        noAns = true;
        return;
    }
    allC.emplace_back(c[u], d[u]);
}

ll C(ll m, ll k) {
    if (k < 0 || m < k) {
        return 0;
    }
    ll res = 1;
    for (ll i = m; i > m - k; --i) {
        res = res * (i % MOD) % MOD;
    }
    return res * ifac[k] % MOD;
}

ll Ans() {
    ll res = 1;
    for (auto p: allC) {
        res = res * C(p.first, p.second) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    init();
    DP(1, 0);
    if (noAns) {
        cout << 0;
    } else {
        cout << Ans();
    }
}
