// Problem:  Luogu P1614 爱与愁的心痛
// Link:     https://www.luogu.com.cn/problem/P1614
// Author:   nine19een
// Date:     2025-10-19

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 3e3 + 5;

ll ans = 1e9 + 5, n, m, pre[maxn], a[maxn];

int main() {
    cin >> n >> m;
    if (!m) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
        if (i >= m) {
            ans = min(ans, pre[i] - pre[i - m]);
        }
    }
    cout << ans;
}