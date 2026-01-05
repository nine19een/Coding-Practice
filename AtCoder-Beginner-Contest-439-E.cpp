// Problem:  AtCoder Beginner Contest 439 E - Kite
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_e
// Author:   nine19een
// Date:     2026-01-06

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

struct Kite {
    int idx, val;
};

int n;
vector<Kite> kite;
vector<int> len;

void updateLen(int x) {
    if (len.empty() || len.back() < x) {
        len.push_back(x);
        return;
    }
    auto it = lower_bound(len.begin(), len.end(), x);
    if (x == len.back() || *it == x) {
        return;
    }
    *it = x;
}

int findLen() {
    sort(kite.begin(), kite.end(), [](const Kite &a, const Kite &b) {
        if (a.idx != b.idx) {
            return a.idx < b.idx;
        } else {
            return a.val > b.val;
        }
    });
    for (Kite &k: kite) {
        updateLen(k.val);
    }
    return (int) len.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    kite.reserve(maxn);
    len.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        kite.push_back({a, b});
    }
    cout << findLen();
    return 0;
}
