// Problem:  Luogu P1182 数列分段 Section II
// Link:     https://www.luogu.com.cn/problem/P1182
// Author:   nine19een
// Date:     2026-04-09

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, m, a[maxn], max_a;
ll sum_a;

ll piece(ll x) {
    int cnt = 1;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum > x) {
            cnt++;
            sum = a[i];
        }
    }
    return cnt;
}

ll Binary() {
    ll l = max_a, r = sum_a;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (piece(mid) <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum_a += a[i];
        max_a = max(max_a, a[i]);
    }
    cout << Binary();
    return 0;
}
