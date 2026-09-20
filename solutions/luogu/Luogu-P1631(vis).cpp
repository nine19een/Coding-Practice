// Problem:  Luogu P1631 序列合并
// Link:     https://www.luogu.com.cn/problem/P1631
// Author:   nine19een
// Date:     2026-01-14
// Method:   状压哈希表vis去重

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct S {
    ll sum;
    int idx_a, idx_b;
};

int n;
unordered_map<ll, bool> vis;

struct cmp {
    bool operator()(const S &a, const S &b) {
        return a.sum > b.sum;
    }
};

ll getKey(ll a, ll b) {
    ll key = (a << 32) | b;
    return key;
}

void findMinSum(const vector<ll> &a, const vector<ll> &b) {
    priority_queue<S, vector<S>, cmp> pq;
    pq.push({a[0] + b[0], 0, 0});
    int cnt = 1;
    int max_idx = n - 1;
    while (cnt <= n) {
        auto t = pq.top();
        pq.pop();
        ll key = getKey(t.idx_a, t.idx_b);
        if (vis.count(key)) {
            continue;
        }
        vis[key] = true;
        cout << t.sum << " ";
        cnt++;
        if (t.idx_a < max_idx) {
            pq.push({t.sum - a[t.idx_a] + a[t.idx_a + 1], t.idx_a + 1, t.idx_b});
        }
        if (t.idx_b < max_idx) {
            pq.push({t.sum - b[t.idx_b] + b[t.idx_b + 1], t.idx_a, t.idx_b + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    findMinSum(a, b);
    return 0;
}
