// Problem:  AtCoder Beginner Contest 442 D - Swap and Range Sum
// Link:     https://atcoder.jp/contests/abc438/tasks/abc442_d
// Author:   nine19een
// Date:     2026-01-24

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5, maxN = 4 * maxn;

ll n, q, a[maxn], tree[maxN];

inline int ls(int p) {
    return p << 1;
}

inline int rs(int p) {
    return p << 1 | 1;
}

inline void pushUp(int p) {
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

void Build(int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(ls(p), l, mid);
    Build(rs(p), mid + 1, r);
    pushUp(p);
}

void Update(int p, int l, int r, int idx, ll val) {
    if (l == r) {
        tree[p] = val;
        a[idx] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) {
        Update(ls(p), l, mid, idx, val);
    } else {
        Update(rs(p), mid + 1, r, idx, val);
    }
    pushUp(p);
}

ll Query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    ll sum = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        sum += Query(ls(p), l, mid, ql, qr);
    }
    if (qr > mid) {
        sum += Query(rs(p), mid + 1, r, ql, qr);
    }
    return sum;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    Build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx;
            cin >> idx;
            ll a_next = a[idx + 1];
            Update(1, 1, n, idx + 1, a[idx]);
            Update(1, 1, n, idx, a_next);
        }
        if (op == 2) {
            int Ql, Qr;
            cin >> Ql >> Qr;
            cout << Query(1, 1, n, Ql, Qr) << '\n';
        }
    }
    return 0;
}
