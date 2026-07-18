#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

ll n, m, a[maxn], b[maxn], c[maxn], d[maxn];

ll MOD(ll x) {
    return (x % m + m) % m;
}

void init() {
    for (int i = 1; i < n; ++i) {
        d[i] = MOD(b[i] - a[i] - a[i + 1]);
    }
    for (int i = 1; i < n; ++i) {
        c[i + 1] = MOD(d[i] - c[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }
    init();
    ll cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += c[i];
    }
    ll ans = cur;
    vector<pair<ll, ll> > v;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            if (c[i] > 0) {
                v.push_back({m - c[i], -m});
            }
        } else {
            if (c[i] < m - 1) {
                v.push_back({c[i] + 1, m});
            }
        }
    }
    sort(v.begin(), v.end());
    ll idx = n & 1;
    ll last = 0;
    int i = 0;
    while (i < (int) v.size()) {
        ll pos = v[i].first;
        cur += idx * (pos - last);
        while (i < (int) v.size() && v[i].first == pos) {
            cur += v[i].second;
            ++i;
        }
        ans = min(ans, cur);
        last = pos;
    }
    cout << ans;
    return 0;
}
