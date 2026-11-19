// Luogu P2842 纸币问题 1
// https://www.luogu.com.cn/problem/P2842

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005, maxw = 1e4 + 5, INF = 0x3f3f3f3f;

int n, w, a[maxn], dp[maxw];

void init() {
    for (int i = 1; i <= w; ++i) {
        dp[i] = INF;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j <= w; ++j) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    cout << dp[w];
    return 0;
}
