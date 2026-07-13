// Problem:  2021 CCPC Online F - Nun Heh Heh Aaaaaaaaaaa
// Link:     https://vjudge.net/problem/HDU-7131
// Author:   nine19een
// Date:     2026-07-14

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 998244353;

int t;
string temp = "nunhehheh";

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll DP(const string &s) {
    ll sum = 0;
    int len = (int) s.length();
    vector<int> a(len + 5, 0);
    vector<ll> dp(9, 0);
    dp[0] = 1;
    for (int i = len - 1; i >= 0; --i) {
        if (i != len - 1) {
            a[i] = a[i + 1];
        }
        if (s[i] == 'a') {
            a[i]++;
        }
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 8; j >= 1; --j) {
            if (s[i] == temp[j - 1]) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        if (s[i] == 'h' && dp[8]) {
            sum = (sum + dp[8] * (qpow(2, a[i]) - 1) % mod) % mod;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << DP(s) << '\n';
    }
    return 0;
}
