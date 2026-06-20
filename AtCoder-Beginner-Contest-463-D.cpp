// Problem:  AtCoder Beginner Contest 463 D - Maximize the Gap
// Link:     https://atcoder.jp/contests/abc463/tasks/abc463_d
// Author:   nine19een
// Date:     2026-06-20

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, k;
vector<pair<ll, ll> > v;

bool Check(ll d) {
    int cnt = 1;
    ll last_r = v[0].second;
    for (auto p: v) {
        ll cur_l = p.first, cur_r = p.second;
        if (cur_l - last_r >= d) {
            cnt++;
            last_r = cur_r;
        }
        if (cnt == k) {
            return true;
        }
    }
    return false;
}

ll Binary() {
    ll l = 1, r = 1e9 + 5;
    while (l < r) {
        ll mid = (r - l) / 2 + l;
        if (Check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l == 1 ? -1 : l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int l_i, r_i;
        cin >> l_i >> r_i;
        v.emplace_back(l_i, r_i);
    }
    sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return a.second < b.second;
    });
    cout << Binary();
    return 0;
}
