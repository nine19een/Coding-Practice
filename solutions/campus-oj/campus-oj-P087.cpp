// Campus OJ P087 外星钢琴
// https://oj.nine19een.com/#library/P087

#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    vector<vector<int>> dp(n + 5, vector<int>(5, 0x3f3f3f3f));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                int cost = 1;
                if ((a[i] > a[i - 1] && j > k) || (a[i] < a[i - 1] && j < k) || (a[i] == a[i - 1] && j == k)) {
                    cost = 0;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost);
            }
        }
    }
    cout << min({dp[n][1], dp[n][2], dp[n][3], dp[n][4]}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
