// Problem:  Luogu P1725 琪露诺
// Link:     https://www.luogu.com.cn/problem/P1725
// Author:   nine19een
// Date:     2025-12-09

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 2e5 + 5;

ll n, l, r, a[MAXN], dp[MAXN], ans = LONG_LONG_MIN;

void init_dp() {
    for (int i = 1; i <= n; ++i) {
        dp[i] = LONG_LONG_MIN;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> r;
    ll len = r - l + 1;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    init_dp();
    deque<ll> q;
    for (int i = 0; i + l <= n; i++) {
        if (dp[i] != LONG_LONG_MIN) {
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        if (!q.empty() && q.front() <= i - len) {
            q.pop_front();
        }
        if (!q.empty()) {
            dp[i + l] = dp[q.front()] + a[i + l];
        }
    }
    for (ll i = n - r + 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}