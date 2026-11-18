// Luogu P1616 疯狂的采药
// https://www.luogu.com.cn/problem/P1616

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxt = 1e7 + 5, maxm = 1e4 + 5;

int a[maxm], b[maxm], t, m;
ll dp[maxt];

int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = a[i]; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t];
    return 0;
}
