// Luogu P2871 [USACO07DEC] Charm Bracelet S
// https://www.luogu.com.cn/problem/P2871

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4000, maxm = 13000;

int n, m, w[maxn], d[maxn], dp[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> d[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    }
    cout << dp[m];
    return 0;
}
