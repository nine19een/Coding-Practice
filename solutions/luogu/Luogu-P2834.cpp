// Luogu P2834 纸币问题 3
// https://www.luogu.com.cn/problem/P2834

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005, maxw = 1e4 + 5, MOD = 1e9 + 7;

int n, w, a[maxn], dp[maxw];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j <= w; ++j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << dp[w];
    return 0;
}
