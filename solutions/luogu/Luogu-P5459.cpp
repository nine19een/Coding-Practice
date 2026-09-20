// Problem:  Luogu P5459 [BJOI2016] 回转寿司
// Link:     https://www.luogu.com.cn/problem/P5459
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5, maxN = 3 * maxn;

int n, tr_size;
ll L, R, tr[maxN], pre[maxn], cnt;
vector<ll> pos;

inline int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= tr_size; i += lowbit(i)) {
        tr[i]++;
    }
}

ll query(int x) {
    ll sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += tr[i];
    }
    return sum;
}

inline int get_idx(ll x) {
    return lower_bound(pos.begin(), pos.end(), x) - pos.begin() + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pos.reserve(maxN);
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
        pos.push_back(pre[i]);
        pos.push_back(pre[i] - L);
        pos.push_back(pre[i] - R);
    }
    pos.push_back(0);
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    tr_size = pos.size();
    add(get_idx(0));
    for (int i = 1; i <= n; i++) {
        int idx = get_idx(pre[i]);
        int l = get_idx(pre[i] - R) - 1, r = get_idx(pre[i] - L);
        cnt += query(r) - query(l);
        add(idx);
    }
    cout << cnt;
    return 0;
}
