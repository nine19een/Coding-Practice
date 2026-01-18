// Problem:  AtCoder Beginner Contest 441 F - Must Buy
// Link:     https://atcoder.jp/contests/abc438/tasks/abc441_f
// Author:   nine19een
// Date:     2026-01-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1005, maxm = 5e4 + 5;

struct Item {
    ll p, v;
};

Item it[maxn];
ll pre_dp[maxn][maxm], post_dp[maxn][maxm], max_val;
int n, m;
char ans[maxn];

void Init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j < it[i].p) {
                pre_dp[i][j] = pre_dp[i - 1][j];
                continue;
            }
            pre_dp[i][j] = max(pre_dp[i - 1][j], pre_dp[i - 1][j - it[i].p] + it[i].v);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            if (j < it[i].p) {
                post_dp[i][j] = post_dp[i + 1][j];
                continue;
            }
            post_dp[i][j] = max(post_dp[i + 1][j], post_dp[i + 1][j - it[i].p] + it[i].v);
        }
    }
}

ll maxVal1(int idx) {
    int w = m - it[idx].p;
    ll max_val_1 = 0;
    for (int i = 0; i <= w; ++i) {
        max_val_1 = max(max_val_1, pre_dp[idx - 1][i] + post_dp[idx + 1][w - i]);
    }
    return max_val_1 + it[idx].v;
}

ll maxVal2(int idx) {
    ll max_val_2 = 0;
    for (int i = 0; i <= m; ++i) {
        max_val_2 = max(max_val_2, pre_dp[idx - 1][i] + post_dp[idx + 1][m - i]);
    }
    return max_val_2;
}

void judgeABC() {
    for (int i = 1; i <= n; i++) {
        if (maxVal1(i) < max_val) {
            ans[i] = 'C';
        } else {
            if (maxVal2(i) < max_val) {
                ans[i] = 'A';
            } else {
                ans[i] = 'B';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> it[i].p >> it[i].v;
    }
    Init();
    max_val = pre_dp[n][m];
    judgeABC();
    for (int i = 1; i <= n; ++i) {
        cout << ans[i];
    }
    return 0;
}
