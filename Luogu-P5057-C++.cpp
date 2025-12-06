// Problem:  Luogu P5057 [CQOI2006] 简单题
// Link:     https://www.luogu.com.cn/problem/P5057
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, diff_tree[MAXN];

int lowbit(int x) {
    return x & -x;
}

int query(int x) {
    int sum = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        sum += diff_tree[i];
    }
    return sum;
}

void update(int x, int add) {
    for (int i = x; i <= n; i += lowbit(i)) {
        diff_tree[i] += add;
    }
}

void Reverse(int l, int r) {
    update(l, 1);
    update(r + 1, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            Reverse(l, r);
        } else {
            int idx;
            cin >> idx;
            cout << (query(idx) & 1) << '\n';
        }
    }
}
