// Problem:  Luogu P1063 [NOIP 2006 提高组] 能量项链
// Link:     https://www.luogu.com.cn/problem/P1063
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105, maxN = 205;

struct Node {
    int val, l, r;
} dp[maxn][maxN];

int n, N, ans;

void DP() {
    for (int i = 1; i <= n; i++) {
        const int limit = N - i;
        for (int j = 1; j <= limit; j++) {
            int max_energy = 0;
            for (int k = 1; k < i; k++) {
                int sum = dp[k][j].val + dp[i - k][j + k].val + dp[k][j].l * dp[k][j].r * dp[i - k][j + k].r;
                max_energy = max(max_energy, sum);
            }
            dp[i][j] = {max_energy, dp[1][j].l, dp[1][j + i - 1].r};
            if (i == n) {
                ans = max(ans, dp[i][j].val);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[1][i].l;
        if (i == 1) {
            dp[1][n].r = dp[1][i + n].l = dp[1][i].l;
        } else {
            dp[1][i - 1].r = dp[1][i - 1 + n].r = dp[1][i + n].l = dp[1][i].l;
        }
    }
    N = 2 * n;
    DP();
    cout << ans;
    return 0;
}
