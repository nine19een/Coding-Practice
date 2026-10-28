// Campus OJ P162 飞船能源舱
// https://oj.nine19een.com/#library/P162

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
ll dp[maxn][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + a;
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}