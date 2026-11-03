// Campus OJ P010 欢迎语的子序列
// https://oj.nine19een.com/#library/P010

#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 10000;
using ll = long long;

int t;
string temp = "welcome to code jam";

void solve() {
    string s;
    getline(cin, s);
    vector<ll> dp(20, 0);
    dp[0] = 1;
    for (char c: s) {
        for (int i = 19; i >= 1; i--) {
            if (temp[i - 1] == c) {
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            }
        }
    }
    cout << setw(4) << setfill('0') << dp[19] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
    return 0;
}
