// Problem:  Codeforces School Team Contest 2 (Winter Computer School 2010/11) C. Holidays
// Link:     https://codeforces.com/contest/44/problem/C
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        update(a, 1);
        update(b + 1, -1);
    }
    for (int j = 1; j <= n; ++j) {
        if (query(j) != 1) {
            cout << j << " " << query(j) << '\n';
            return 0;
        }
    }
    cout << "OK";
    return 0;
}
