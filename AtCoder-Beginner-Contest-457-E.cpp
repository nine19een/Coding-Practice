// Problem:  AtCoder Beginner Contest 457 E - Crossing Table Cloth
// Link:     https://atcoder.jp/contests/abc457/tasks/abc457_e
// Author:   nine19een
// Date:     2026-05-10

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll maxn = 2e5 + 5;

struct Query {
    int l, r, id;
};

struct Fenwick {
    int n;
    vector<int> c;

    Fenwick(int _n) : n(_n), c(n + 1, 0) {
    }

    static int lowbit(int x) {
        return x & -x;
    }

    void add(int x) {
        for (int i = x; i <= n; i += lowbit(i)) {
            c[i]++;
        }
    }

    [[nodiscard]] int query(int x) const {
        int sum = 0;
        for (int i = x; i; i -= lowbit(i)) {
            sum += c[i];
        }
        return sum;
    }
};

int n, m, q;
bool ans[maxn];
vector<int> L[maxn], R[maxn];
vector<Query> Q;
unordered_set<ll> exact_LR;

void init() {
    for (int i = 1; i <= n; i++) {
        if (!L[i].empty()) {
            sort(L[i].begin(), L[i].end());
        }
        if (!R[i].empty()) {
            sort(R[i].begin(), R[i].end());
        }
    }
    sort(Q.begin(), Q.end(), [](const Query &a, const Query &b) {
        return a.l > b.l;
    });
}

ll Key(int l, int r) {
    return 1ll * l * maxn + r;
}

bool Joint(int l, int r) {
    if (L[l].empty() || R[r].empty()) {
        return false;
    }
    auto it_r = lower_bound(L[l].begin(), L[l].end(), r);
    auto it_l = upper_bound(R[r].begin(), R[r].end(), l);
    if (it_r == L[l].begin() || it_l == R[r].end()) {
        return false;
    }
    --it_r;
    if (*it_r + 1 >= *it_l) {
        return true;
    }
    return false;
}

bool Exact(int l, int r, const Fenwick &bit) {
    if (!exact_LR.count(Key(l, r))) {
        return false;
    }
    if (bit.query(r) > 1) {
        return true;
    } else {
        return false;
    }
}

void Solve() {
    Fenwick bit(n);
    int cur_L = n;
    for (Query qy: Q) {
        while (cur_L >= qy.l) {
            for (int r: L[cur_L]) {
                bit.add(r);
            }
            cur_L--;
        }
        if (Joint(qy.l, qy.r) || Exact(qy.l, qy.r, bit)) {
            ans[qy.id] = true;
        }
    }
}

void printANS() {
    for (int i = 1; i <= q; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        L[l].push_back(r);
        R[r].push_back(l);
        exact_LR.insert(Key(l, r));
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int s, t;
        cin >> s >> t;
        Q.push_back({s, t, i});
    }
    init();
    Solve();
    printANS();
    return 0;
}
