// Problem:  2021 CCPC Online E - Monopoly
// Link:     https://vjudge.net/problem/HDU-7130
// Author:   nine19een
// Date:     2026-07-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;

ll mod(ll a, ll b) {
    return (a % b + b) % b;
}

void solve1(int m, unordered_map<ll, int> &f1st) {
    f1st[0] = 0;
    for (int i = 1; i <= m; i++) {
        ll x;
        cin >> x;
        if (f1st.count(x)) {
            cout << f1st[x] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

void solve2(int n, int m, ll s, vector<ll> &pre, unordered_map<ll, vector<pair<ll, ll> > > &same_rem) {
    for (int i = 0; i < n; i++) {
        ll rem = mod(pre[i], abs(s));
        ll k = (pre[i] - rem) / abs(s);
        ll val;
        if (s > 0) {
            val = i - k * n;
        } else {
            val = i + k * n;
        }
        same_rem[rem].push_back({pre[i], val});
    }
    unordered_map<ll, vector<ll> > best;
    for (auto &um: same_rem) {
        ll rem = um.first;
        sort(um.second.begin(), um.second.end());
        int size = um.second.size();
        best[rem] = vector<ll>(size);
        if (s > 0) {
            best[rem][0] = um.second[0].second;
            for (int i = 1; i < size; i++) {
                best[rem][i] = min(best[rem][i - 1], um.second[i].second);
            }
        } else {
            best[rem][size - 1] = um.second[size - 1].second;
            for (int i = size - 2; i >= 0; i--) {
                best[rem][i] = min(best[rem][i + 1], um.second[i].second);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        ll x;
        cin >> x;
        if (!x) {
            cout << 0 << '\n';
            continue;
        }
        ll d = abs(s);
        ll rem = mod(x, d);
        if (!same_rem.count(rem)) {
            cout << -1 << '\n';
            continue;
        }
        auto &v = same_rem[rem];
        if (s > 0) {
            int idx = upper_bound(v.begin(), v.end(), x, [](ll val, const auto &p) {
                return val < p.first;
            }) - v.begin() - 1;
            if (idx < 0) {
                cout << -1 << '\n';
                continue;
            }
            ll h = (x - rem) / s;
            cout << h * n + best[rem][idx] << '\n';
        } else {
            int idx = lower_bound(v.begin(), v.end(), x, [](const auto &p, ll val) {
                return p.first < val;
            }) - v.begin();
            if (idx == (int) v.size()) {
                cout << -1 << '\n';
                continue;
            }
            ll h = (x - rem) / d;
            cout << -h * n + best[rem][idx] << '\n';
        }
    }
}

void op() {
    int n, m;
    cin >> n >> m;
    ll s = 0;
    vector<int> a(n + 5);
    vector<ll> pre(n + 5, 0);
    unordered_map<ll, int> f1st;
    unordered_map<ll, vector<pair<ll, ll> > > same_rem;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        if (!f1st.count(s)) {
            f1st[s] = i;
        }
        if (i != n) {
            pre[i] = s;
        }
    }
    if (!s) {
        solve1(m, f1st);
    } else {
        pre[0] = 0;
        solve2(n, m, s, pre, same_rem);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
