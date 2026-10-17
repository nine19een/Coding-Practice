// AtCoder Beginner Contest 480 D - Concatenation of Prefixes
// https://atcoder.jp/contests/abc480/tasks/abc480_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, q;
ll a[maxn], pre[maxn], sum[maxn];

ll query(ll x) {
    if (x == 0) {
        return 0;
    }
    int l = 1, r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        ll cnt = 1ll * mid * (mid + 1) / 2;
        if (cnt >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ll pos = x - 1LL * l * (l - 1) / 2;
    return sum[l - 1] + pre[pos];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        sum[i] = sum[i - 1] + pre[i];
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << '\n';
    }
    return 0;
}
