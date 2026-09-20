// Problem:  蓝桥杯 2026 省 B H题 - 足球训练
// Link:     https://www.luogu.com.cn/problem/P16239
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int maxn = 1e5 + 5, mod = 998244353, inf = 1e9 + 1e5 + 10;

struct node {
    ld level;
    int id;

    bool operator>(const node &other) const {
        return level > other.level;
    }
};

int n, m, a[maxn], b[maxn];
ll k[maxn], rest;
ld x[maxn];

bool Check(ld t) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += max(0ll, (ll) floor(t - x[i]) + 1);
        if (cnt > m) {
            return false;
        }
    }
    return true;
}

ld Binary() {
    ld l = 0, r = inf;
    for (int i = 1; i <= 100; ++i) {
        ld mid = l + (r - l) / 2;
        if (Check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void solve(ld t) {
    rest = m;
    for (int i = 1; i <= n; ++i) {
        k[i] = max(0ll, (ll) floor(t - x[i]) + 1);
        rest -= k[i];
    }
    priority_queue<node, vector<node>, greater<node> > pq;
    for (int i = 1; i <= n; ++i) {
        pq.push({x[i] + k[i], i});
    }
    while (rest--) {
        int t_id = pq.top().id;
        pq.pop();
        k[t_id]++;
        pq.push({x[t_id] + k[t_id], t_id});
    }
}

ll Ans() {
    ll result = 1;
    for (int i = 1; i <= n; ++i) {
        result = result * ((a[i] + 1ll * b[i] * k[i]) % mod) % mod;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        x[i] = 1.0l * a[i] / b[i];
    }
    solve(Binary());
    cout << Ans();
    return 0;
}
