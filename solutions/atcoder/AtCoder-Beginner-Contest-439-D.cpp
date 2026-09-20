// Problem:  AtCoder Beginner Contest 439 D - Kadomatsu Subsequence
// Link:     https://atcoder.jp/contests/abc439/tasks/abc439_d
// Author:   nine19een
// Date:     2026-01-04

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
unordered_map<int, vector<int> > time3;
unordered_map<int, vector<int> > time5;
unordered_map<int, vector<int> > time7;

void init(int idx, int x) {
    if (x % 3 == 0) {
        time3[x / 3].push_back(idx);
    }
    if (x % 5 == 0) {
        time5[x / 5].push_back(idx);
    }
    if (x % 7 == 0) {
        time7[x / 7].push_back(idx);
    }
}

ll Cnt() {
    ll cnt = 0;
    for (const auto &p: time5) {
        auto It3 = time3.find(p.first), It7 = time7.find(p.first);
        if (It3 == time3.end() || It7 == time7.end()) {
            continue;
        }
        auto &v3 = It3->second, &v7 = It7->second;
        sort(v3.begin(), v3.end());
        sort(v7.begin(), v7.end());
        for (int q: p.second) {
            auto it3 = lower_bound(v3.begin(), v3.end(), q);
            auto it7 = lower_bound(v7.begin(), v7.end(), q);
            ll cnt_min_3 = (ll) (it3 - v3.begin());
            ll cnt_max_3 = (ll) v3.size() - cnt_min_3;
            ll cnt_min_7 = (ll) (it7 - v7.begin());
            ll cnt_max_7 = (ll) v7.size() - cnt_min_7;
            cnt += cnt_min_3 * cnt_min_7 + cnt_max_3 * cnt_max_7;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        init(i, x);
    }
    cout << Cnt();
    return 0;
}
