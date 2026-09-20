// Problem:  AtCoder Beginner Contest 459 E - Select from Subtrees
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_e
// Author:   nine19een
// Date:     2026-05-24

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5, maxd = 1e6 + 5, MOD = 998244353;

int n;
ll fac = 1, ifac[maxd], c[maxn], d[maxn], ans = 1;
bool noAns;
vector<int> adj[maxn];

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
    ifac[0] = 1;
    for (int i = 1; i < maxd; ++i) {
        fac = fac * i % MOD;
    }
    ifac[maxd - 1] = qpow(fac, MOD - 2);
    for (int i = maxd - 2; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
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

void DP(int u) {
    for (int v: adj[u]) {
        DP(v);
        if (noAns) {
            return;
        }
        c[u] += c[v] - d[v];
    }
    if (c[u] < d[u]) {
        noAns = true;
        return;
    }
    ans = ans * C(c[u], d[u]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    init();
    DP(1);
    if (noAns) {
        cout << 0;
    } else {
        cout << ans;
    }
}
