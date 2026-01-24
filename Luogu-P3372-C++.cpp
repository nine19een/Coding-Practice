// Problem:  Luogu P3372 【模板】线段树 1
// Link:     https://www.luogu.com.cn/problem/P3372
// Author:   nine19een
// Date:     2026-01-24

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5, maxN = 4 * maxn;

int n, m;
ll a[maxn], tree[maxN], lazy[maxN];

inline int ls(int p) {
    return p << 1;
}

inline int rs(int p) {
    return p << 1 | 1;
}

inline void pushUp(int p) {
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

inline void pushDown(int p, int l, int r) {
    if (!lazy[p]) {
        return;
    }
    int mid = (l + r) >> 1;
    tree[ls(p)] += (mid - l + 1) * lazy[p];
    lazy[ls(p)] += lazy[p];
    tree[rs(p)] += (r - mid) * lazy[p];
    lazy[rs(p)] += lazy[p];
    lazy[p] = 0;
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

void Update(int p, int l, int r, int ul, int ur, ll k) {
    if (ul <= l && r <= ur) {
        tree[p] += (r - l + 1) * k;
        lazy[p] += k;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid) {
        Update(ls(p), l, mid, ul, ur, k);
    }
    if (ur > mid) {
        Update(rs(p), mid + 1, r, ul, ur, k);
    }
    pushUp(p);
}

ll Query(int p, int l, int r, int ul, int ur) {
    ll sum = 0;
    if (ul <= l && r <= ur) {
        sum += tree[p];
        return sum;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid) {
        sum += Query(ls(p), l, mid, ul, ur);
    }
    if (ur > mid) {
        sum += Query(rs(p), mid + 1, r, ul, ur);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    Build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            ll k;
            cin >> x >> y >> k;
            Update(1, 1, n, x, y, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << Query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}