// Problem:  SP2815 INCSEQ - Increasing Subsequences
// Link:     (En)https://www.spoj.com/problems/INCSEQ/   (Ch)https://www.luogu.com.cn/problem/P4054
// Author:   nine19een
// Date:     2025-12-11

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e4 + 5, MOD = 5000000;

ll n, k;
vector<ll> a, coord;

int lowbit(int x) {
    return x & -x;
}

void update(int idx, ll val, vector<ll> &tree, int limit) {
    for (int i = idx; i <= limit; i += lowbit(i)) {
        tree[i] = (tree[i] + val) % MOD;
    }
}

ll query(int idx, const vector<ll> &tree) {
    ll sum = 0;
    for (int i = idx; i; i -= lowbit(i)) {
        sum = (sum + tree[i]) % MOD;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    coord.reserve(maxn);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        ll num;
        cin >> num;
        a.push_back(num);
        coord.push_back(num);
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    int size = (int) coord.size();
    vector<vector<ll> > dp_tree(k + 5, vector<ll>(size + 5, 0));
    for (ll p: a) {
        int idx = (int) (lower_bound(coord.begin(), coord.end(), p) - coord.begin()) + 1;
        for (int i = 2; i <= k; ++i) {
            update(idx, query(idx - 1, dp_tree[i - 1]), dp_tree[i], size);
        }
        update(idx, 1, dp_tree[1], size);
    }
    cout << query(size, dp_tree[k]);
    return 0;
}
