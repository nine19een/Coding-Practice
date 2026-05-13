// Problem:  Luogu P4231 三步必杀
// Link:     https://www.luogu.com.cn/problem/P4231
// Author:   nine19een
// Date:     2025-12-02
// Method:   单数组二阶差分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 1e7 + 5;

ll n, m, diff[maxn], XOR, max_val;

void Diff(ll l, ll r, ll s, ll e, ll d) {
    diff[l] += s;
    diff[l + 1] += d - s;
    diff[r + 1] -= e + d;
    diff[r + 2] += e;
}

void sum() {
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        max_val = max(max_val, diff[i]);
        XOR ^= diff[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ll l, r, s, e;
        cin >> l >> r >> s >> e;
        Diff(l, r, s, e, (e - s) / (r - l));
    }
    sum();
    cout << XOR << " " << max_val;
    return 0;
}