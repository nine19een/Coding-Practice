// Luogu P2840 纸币问题 2
// https://www.luogu.com.cn/problem/P2840

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
    for (int j = 1; j <= w; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (j >= a[i]) {
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
            }
        }
    }
    cout << dp[w];
    return 0;
}
