// Campus OJ P161 星光阶梯
// https://oj.nine19een.com/#library/P161

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 50;

int n;
ll dp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}