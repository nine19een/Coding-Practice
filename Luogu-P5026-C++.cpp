// Problem:  Luogu P5026 Lycanthropy
// Link:     https://www.luogu.com.cn/problem/P5026
// Author:   nine19een
// Date:     2025-12-02

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxm = 2e6 + 5, dv = 3e4 + 5;

ll n, m, diff[maxm];

void Diff(ll v, ll x) {
    diff[x - 3 * v + 1]++;
    diff[x - 2 * v + 1] -= 2;
    diff[x + 1] += 2;
    diff[x + 2 * v + 1] -= 2;
    diff[x + 3 * v + 1]++;
}

void sum() {
    ll M = m + dv;
    for (int round = 1; round <= 2; ++round) {
        for (int i = 1; i <= M; ++i) {
            diff[i] += diff[i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v, x;
        cin >> v >> x;
        Diff(v, x + dv);
    }
    sum();
    for (int i = 1; i <= m; i++) {
        cout << diff[i + dv] << " ";
    }
    return 0;
}
