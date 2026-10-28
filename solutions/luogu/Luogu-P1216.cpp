// Luogu P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
// https://www.luogu.com.cn/problem/P1216

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;

int r, a[maxn][maxn], dp[maxn][maxn], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
            }
            if (i == r) {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}