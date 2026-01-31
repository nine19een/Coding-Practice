// Problem:  AtCoder Beginner Contest 443 E - Climbing Silver
// Link:     https://atcoder.jp/contests/abc443/tasks/abc443_e
// Author:   nine19een
// Date:     2026-02-01

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3005;

int n, c, dx[] = {1, 1, 1}, dy[] = {-1, 0, 1}, wall[maxn];
char maze[maxn][maxn];
bool dp[maxn][maxn], column[maxn];

inline bool in_range(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
};

inline bool available(int i, int j) {
    if (maze[i][j] == '.' || column[j]) {
        return true;
    }
    if (i >= wall[j]) {
        column[j] = true;
        return true;
    }
    return false;
}

void DP() {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (in_range(x, y) && dp[x][y] && available(i, j)) {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }
}

void op() {
    cin >> n >> c;
    memset(wall, 0, sizeof wall);
    for (int i = 1; i <= n; i++) {
        column[i] = false;
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
            dp[i][j] = false;
            if (maze[i][j] == '#') {
                wall[j] = i;
            }
        }
    }
    column[c] = true;
    dp[n][c] = true;
    DP();
    for (int i = 1; i <= n; i++) {
        cout << dp[1][i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
