// Luogu P2722 [USACO3.1] 总分 Score Inflation
// https://www.luogu.com.cn/problem/P2722

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 5;

int n, m, p[maxn], t[maxn], dp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = t[i]; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
        }
    }
    cout << dp[m];
    return 0;
}
