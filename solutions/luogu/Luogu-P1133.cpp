// Problem:  Luogu P1133 教主的花园
// Link:     https://www.luogu.com.cn/problem/P1133
// Author:   nine19een
// Date:     2025-10-24

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 1e5 + 5;

struct Plant_Position {
    ll ten, twenty, thirty;
};

ll n, dp[maxn][5][5], ans;
Plant_Position pos[maxn];

void DP() {
    ll ans = 0;
    for (int i = 1; i <= 3; i++) {
        if (i == 1) {
            dp[1][1][0] = pos[1].ten;
        }
        else if (i == 2) {
            dp[1][2][0] = pos[1].twenty, dp[1][2][1] = pos[1].twenty;
        }
        else if (i == 3) {
            dp[1][3][1] = pos[1].thirty;
        }
        for (int j = 2; j <= n; j++) {
            dp[j][1][0] = max(dp[j - 1][2][1], dp[j - 1][3][1]) + pos[j].ten;
            dp[j][2][0] = dp[j - 1][3][1] + pos[j].twenty;
            dp[j][2][1] = dp[j - 1][1][0] + pos[j].twenty;
            dp[j][3][1] = max(dp[j - 1][1][0], dp[j - 1][2][0]) + pos[j].thirty;
        }
        if (i == 1) {
            ans = max(ans, max(dp[n][2][1], dp[n][3][1]));
        }
        else if (i == 2) {
            ans = max(ans, max(dp[n][1][0], dp[n][3][1]));
        }
        else if (i == 3) {
            ans = max(ans, max(dp[n][1][0], dp[n][2][0]));
        }
        memset(dp, 0, sizeof(dp));
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i].ten >> pos[i].twenty >> pos[i].thirty;
    }
    DP();
    return 0;
}
