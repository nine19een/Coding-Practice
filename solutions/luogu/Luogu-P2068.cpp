// Problem:  Luogu P2068 统计和
// Link:     https://www.luogu.com.cn/problem/P2068
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1e5 + 5;

ll n, w, a[MAXN], tree[MAXN];

ll lowbit(ll x) {
    return x & -x;
}

ll query(ll x) {
    ll sum = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

void update(ll x, ll add) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[i] += add;
    }
}

void opX() {
    ll a, b;
    cin >> a >> b;
    update(a, b);
}

void opY() {
    ll a, b;
    cin >> a >> b;
    cout << query(b) - query(a - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= w; ++i) {
        char c;
        cin >> c;
        if (c == 'x') {
            opX();
        } else {
            opY();
        }
    }
}
