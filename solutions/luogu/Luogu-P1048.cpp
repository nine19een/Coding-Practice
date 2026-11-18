// Luogu P1048 [NOIP 2005 普及组] 采药
// https://www.luogu.com.cn/problem/P1048

#include<bits/stdc++.h>
using namespace std;
constexpr int maxt = 1005, maxm = 105;

int T, M, dp[maxt], t[maxm], v[maxm];

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = T; j >= t[i]; --j) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
    cout << dp[T];
    return 0;
}
