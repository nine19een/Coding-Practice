// Luogu P1115 - 最大子段和
// https://www.luogu.com.cn/problem/P1115

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, dp[maxn], ans = -INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (i == 1) {
            dp[1] = num;
        } else {
            dp[i] = max(num, dp[i - 1] + num);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}