// Problem:  Luogu P10429 [蓝桥杯 2024 省 B] 拔河
// Link:     https://www.luogu.com.cn/problem/P10429
// Author:   nine19een
// Date:     2026-04-08

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 1e3 + 5;

int n, a[maxn];
multiset<ll> st;
ll pre[maxn], ans = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            st.insert(pre[i - 1] - pre[j - 1]);
        }
        for (int j = i; j <= n; ++j) {
            ll aim = pre[j] - pre[i - 1];
            auto it = st.upper_bound(aim);
            if (it == st.end()) {
                ans = min(ans, abs(aim - *prev(it)));
            } else if (it == st.begin()) {
                ans = min(ans, abs(aim - *it));
            } else {
                ans = min(ans, min(abs(aim - *prev(it)), abs(aim - *it)));
            }
        }
    }
    cout << ans;
    return 0;
}
