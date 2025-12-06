// Problem:  AtCoder Beginner Contest 435 E - Cover query
// Link:     https://atcoder.jp/contests/abc435/tasks/abc435_e
// Author:   nine19een
// Date:     2025-12-07

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q, black_len;
set<pair<ll, ll> > black;

void blacking(ll newl, ll newr) {
    auto it = black.lower_bound({newl, 0});
    if (!black.empty() && it != black.begin()) {
        auto prev_it = prev(it);
        it = (prev_it->second >= newl - 1) ? prev_it : it;
    }
    while (it != black.end() && it->first <= newr + 1) {
        black_len -= it->second - it->first + 1;
        newl = min(newl, it->first);
        newr = max(newr, it->second);
        it = black.erase(it);
    }
    black.insert({newl, newr});
    black_len += newr - newl + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        ll l, r;
        cin >> l >> r;
        blacking(l, r);
        cout << n - black_len << '\n';
    }
}
