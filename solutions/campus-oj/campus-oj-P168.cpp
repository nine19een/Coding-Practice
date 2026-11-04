// Campus OJ P168 训练视频剪辑
// https://oj.nine19een.com/#library/P168

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, a[maxn], b[maxn], c[maxn];
ll dp[maxn][2]; //0->a  1->b

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - c[i]) + a[i];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - c[i]) + b[i];
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
