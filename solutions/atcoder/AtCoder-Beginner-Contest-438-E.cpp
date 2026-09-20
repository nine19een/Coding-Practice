// Problem:  AtCoder Beginner Contest 438 E - Heavy Buckets
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_e
// Author:   nine19een
// Date:     2025-12-30

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
using ll = long long;

struct Bucket {
    ll idx, sum;
};

ll n, q, a[maxn];
Bucket dp[maxn][30];

void build() {
    for (int i = 1; i <= n; ++i) {
        dp[i][1].idx = a[i];
        dp[i][1].sum = i;
    }
    for (int k = 2; k <= 30; ++k) {
        for (int i = 1; i <= n; ++i) {
            dp[i][k].idx = dp[dp[i][k - 1].idx][k - 1].idx;
            dp[i][k].sum = dp[i][k - 1].sum + dp[dp[i][k - 1].idx][k - 1].sum;
        }
    }
}

void query(ll t, ll b) {
    ll ans = 0;
    int cnt = 1;
    while (1) {
        if (t & 1) {
            ans += dp[b][cnt].sum;
            b = dp[b][cnt].idx;
        }
        cnt++;
        t >>= 1;
        if (cnt > 30) {
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build();
    for (int i = 1; i <= q; ++i) {
        ll t, b;
        cin >> t >> b;
        query(t, b);
    }
    return 0;
}
