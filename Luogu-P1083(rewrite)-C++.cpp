// Problem:  Luogu P1083 [NOIP 2012 提高组] 借教室
// Link:     https://www.luogu.com.cn/problem/P1083
// Author:   nine19een
// Date:     2025-11-26

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 1e6 + 5;

struct Order {
    ll cnt_rent, l, r;
};

ll n, m;
ll room[maxn], diff[maxn], check[maxn];
Order o[maxn];

void init_diff() {
    for (int i = 1; i <= n; i++) {
        diff[i] = room[i] - room[i - 1];
    }
}

bool isZero(ll idx) {
    init_diff();
    for (int i = 1; i <= idx; i++) {
        diff[o[i].l] -= o[i].cnt_rent;
        diff[o[i].r + 1] += o[i].cnt_rent;
    }
    for (int i = 1; i <= n; i++) {
        check[i] = diff[i] + check[i - 1];
        if (check[i] < 0) {
            return true;
        }
    }
    return false;
}

void LowerBound() {
    ll left = 1, right = m;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (isZero(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << -1 << endl << left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> room[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> o[i].cnt_rent >> o[i].l >> o[i].r;
    }
    if (!isZero(m)) {
        cout << 0;
        return 0;
    }
    LowerBound();
    return 0;
}
