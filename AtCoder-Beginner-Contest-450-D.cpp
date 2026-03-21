// Problem:  AtCoder Beginner Contest 450 D - Minimize Range
// Link:     https://atcoder.jp/contests/abc450/tasks/abc450_d
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;
using ll = long long;

ll n, k, max_interspace;
vector<ll> r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    r.reserve(maxn);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        r.push_back(a % k);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    int size = (int) r.size();
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            max_interspace = max(max_interspace, r[i] + k - r[size - 1]);
            continue;
        }
        max_interspace = max(max_interspace, r[i] - r[i - 1]);
    }
    cout << k - max_interspace;
    return 0;
}
