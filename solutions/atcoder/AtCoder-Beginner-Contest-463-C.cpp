// Problem:  AtCoder Beginner Contest 463 C - Tallest at the Moment
// Link:     https://atcoder.jp/contests/abc463/tasks/abc463_c
// Author:   nine19een
// Date:     2026-06-20

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

int n, q;
vector<int> l;
unordered_map<int, int> um;

inline int IDX(int x) {
    return static_cast<int>(upper_bound(l.begin(), l.end(), x) - l.begin());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    l.reserve(maxn);
    for (int i = 1; i <= n; ++i) {
        int hi, li;
        cin >> hi >> li;
        l.push_back(li);
        um[li] = max(um[li], hi);
    }
    sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
    int size = static_cast<int>(l.size());
    vector max_val(size + 5, 0);
    int cur_max = 0;
    for (int i = size - 1; i >= 0; --i) {
        max_val[i] = max(cur_max, um[l[i]]);
        cur_max = max_val[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        cout << max_val[IDX(t)] << '\n';
    }
    return 0;
}
