// Problem:  AtCoder Beginner Contest 464 E - Fill-Rect Query
// Link:     https://atcoder.jp/contests/abc464/tasks/abc464_e
// Author:   nine19een
// Date:     2026-06-27

#include <bits/stdc++.h>
using namespace std;
constexpr int maxQ = 2e5 + 5;

int h, w, q;
char X[maxQ];

void DP(vector<vector<int> > &dp) {
    for (int i = h; i >= 1; --i) {
        for (int j = w; j >= 1; --j) {
            dp[i][j] = max({dp[i][j], dp[i][j + 1], dp[i + 1][j]});
        }
    }
}

void Print(const vector<vector<int> > &dp) {
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << (!dp[i][j] ? 'A' : X[dp[i][j]]);
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> q;
    vector<vector<int> > dp(h + 5, vector<int>(w + 5, 0));
    for (int i = 1; i <= q; ++i) {
        int r, c;
        cin >> r >> c >> X[i];
        dp[r][c] = i;
    }
    DP(dp);
    Print(dp);
    return 0;
}
