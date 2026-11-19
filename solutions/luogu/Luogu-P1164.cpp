// Luogu P1164 小A点菜
// https://www.luogu.com.cn/problem/P1164

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 105, maxm = 1e4 + 5;

int n, m, a[maxn], dp[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= a[i]; --j) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m];
    return 0;
}
