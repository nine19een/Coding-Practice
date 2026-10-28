// Campus OJ P059 没有怪物的安全正方形
// https://oj.nine19een.com/#library/P059

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

int getHash(int x, int y) {
    return x * 3001 + y;
}

void solve() {
    unordered_set<int> monster;
    int r, c, k;
    ll sum = 0;
    cin >> r >> c >> k;
    vector<vector<int>> dp(r + 5, vector<int> (c + 5, 1));
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        monster.insert(getHash(x, y));
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == 0 || j == 0) {
                if (monster.count(getHash(i, j))) {
                    dp[i][j] = 0;
                } else {
                    sum += 1;
                }
                continue;
            }
            if (monster.count(getHash(i, j))) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            sum += dp[i][j];
        }
    }
    cout << sum << '\n';
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