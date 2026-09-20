// Problem:  AtCoder Beginner Contest 442 C - Peer Review
// Link:     https://atcoder.jp/contests/abc442/tasks/abc442_c
// Author:   nine19een
// Date:     2026-01-24

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n, m, cnt[maxn];

ll C(ll a, ll b) {
    if (b > a) {
        return 0;
    }
    ll A = 1, B = 1;
    int cnt_b = b;
    while (cnt_b--) {
        A *= a--;
        B *= b--;
    }
    return A / B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << C(n - cnt[i] - 1, 3) << '\n';
    }
    return 0;
}
