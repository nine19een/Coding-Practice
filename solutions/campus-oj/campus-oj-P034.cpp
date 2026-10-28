// Campus OJ P034 月亮与雨伞
// https://oj.nine19een.com/#library/P034

#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

int t;

void solve() {
    int x, y;
    string s;
    cin >> x >> y >> s;
    int len = s.length();
    vector<pair<int, int> > dp(len + 5, {INF, INF}); // first -> C second -> J
    if (s[0] != 'J') {
        dp[0].first = 0;
    }
    if (s[0] != 'C') {
        dp[0].second = 0;
    }
    for (int i = 1; i < len; ++i) {
        if (s[i] != 'J') {
            dp[i].first = min(dp[i - 1].first, dp[i - 1].second + y);
        }
        if (s[i] != 'C') {
            dp[i].second = min(dp[i - 1].second, dp[i - 1].first + x);
        }
    }
    cout << min(dp[len - 1].first, dp[len - 1].second) << '\n';
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