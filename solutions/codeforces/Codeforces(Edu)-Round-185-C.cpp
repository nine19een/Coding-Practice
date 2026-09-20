// Problem:  Educational Codeforces Round 185 C. Quotient and Remainder
// Link:     https://codeforces.com/contest/2170/problem/C
// Author:   nine19een
// Date:     2025-11-29

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool available(ll q, ll r, ll k) {
    return (r + 1) * q + r <= k;
}

void op() {
    ll n, k, cnt = 0;
    cin >> n >> k;
    vector<ll> q(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    int idx_q = 0, idx_r = n - 1;
    while (idx_q < n && idx_r >= 0) {
        if (available(q[idx_q], r[idx_r], k)) {
            cnt++;
            idx_q++;
            idx_r--;
        } else {
            idx_r--;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
