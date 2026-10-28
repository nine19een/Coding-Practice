// Campus OJ P163 花园巡查路线
// https://oj.nine19een.com/#library/P163

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 25;

int n, m;
char grid[maxn][maxn];
ll dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                dp[i][j] = 1;
                continue;
            }
            if (i == 1) {
                dp[i][j] = grid[i][j] == '.' ? dp[i][j - 1] : 0;
            }
            if (j == 1) {
                dp[i][j] = grid[i][j] == '.' ? dp[i - 1][j] : 0;
            }
            dp[i][j] = grid[i][j] == '.' ? dp[i][j - 1] + dp[i - 1][j] : 0;
        }
    }
    cout << dp[n][m];
    return 0;
}