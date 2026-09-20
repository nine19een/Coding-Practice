// Problem:  Luogu P12134 [蓝桥杯 2025 省 B] 画展布置
// Link:     https://www.luogu.com.cn/problem/P12134
// Author:   nine19een
// Date:     2026-04-07

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 1e5 + 5, INF = LLONG_MAX;


int n, m, a[maxn];
ll pre[maxn], sum, ans = INF;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i) {
        pre[i - 1] = 1ll * a[i] * a[i] - 1ll * a[i - 1] * a[i - 1];
    }
    for (int i = 1; i < m; ++i) {
        sum += pre[i];
    }
    int l = 1, r = m - 1;
    while (r < n) {
        if (l != 1) {
            sum += pre[r] - pre[l - 1];
        }
        ans = min(ans, sum);
        l++;
        r++;
    }
    cout << ans;
    return 0;
}
