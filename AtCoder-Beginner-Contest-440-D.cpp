// Problem:  AtCoder Beginner Contest 440 D - Forbidden List 2
// Link:     https://atcoder.jp/contests/abc440/tasks/abc440_d
// Author:   nine19een
// Date:     2026-01-13

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18, maxn = 3e5 + 5;

int n, q;
vector<int> a;

ll findAns(ll x, ll y) {
    ll p = lower_bound(a.begin(), a.end(), x) - a.begin();
    ll l = x, r = x + y + n;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll cnt = (mid - x + 1) - (upper_bound(a.begin(), a.end(), mid) - a.begin() - p);
        if (cnt < y) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
        cout << findAns(x, y) << '\n';
    }
    return 0;
}
