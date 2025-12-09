// Problem:  Luogu P1972 [SDOI2009] HH 的项链
// Link:     https://www.luogu.com.cn/problem/P1972
// Author:   nine19een
// Date:     2025-12-10

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

struct Query {
    int l, r, id;
};

int n, m, tree[maxn], a[maxn], ans[maxn];
vector<Query> Q;
unordered_map<int, int> last_idx;

int lowbit(int x) {
    return x & -x;
}

void update(int x, int add) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[i] += add;
    }
}

int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

void update_right(int r) {
    if (!last_idx.count(a[r])) {
        update(r, 1);
        last_idx[a[r]] = r;
    } else {
        update(last_idx[a[r]], -1);
        update(r, 1);
        last_idx[a[r]] = r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        Q.push_back({l, r, i});
    }
    sort(Q.begin(), Q.end(), [](const Query &a, const Query &b) {
        return a.r < b.r;
    });
    int cur_r = 0;
    for (const Query &q: Q) {
        while (cur_r != q.r) {
            update_right(++cur_r);
        }
        ans[q.id] = query(q.r) - query(q.l - 1);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
