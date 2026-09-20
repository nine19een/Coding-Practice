// Problem:  Luogu P1637 三元上升子序列
// Link:     https://www.luogu.com.cn/problem/P1637
// Author:   nine19een
// Date:     2025-12-10

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 3e4 + 5;

ll n, ans;
vector<ll> a, disperse;

ll lowbit(ll x) {
    return x & -x;
}

void update(ll x, ll add, vector<ll> &tree, ll limit) {
    for (ll i = x; i <= limit; i += lowbit(i)) {
        tree[i] += add;
    }
}

ll query(ll x, vector<ll> &tree) {
    ll sum = 0;
    for (ll i = x; i; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    disperse.reserve(maxn);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        ll num;
        cin >> num;
        a.push_back(num);
        disperse.push_back(num);
    }
    sort(disperse.begin(), disperse.end());
    disperse.erase(unique(disperse.begin(), disperse.end()), disperse.end());
    vector<ll> double_pair(disperse.size() + 5, 0);
    vector<ll> cnt_op(disperse.size() + 5, 0);
    for (ll p: a) {
        ll idx = lower_bound(disperse.begin(), disperse.end(), p) - disperse.begin() + 1;
        ans += query(idx - 1, double_pair);
        update(idx, query(idx - 1, cnt_op), double_pair, (ll) disperse.size());
        update(idx, 1, cnt_op, (ll) disperse.size());
    }
    cout << ans;
    return 0;
}
