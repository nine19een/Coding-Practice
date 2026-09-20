// Problem:  Luogu P1880 [NOI1995] 石子合并
// Link:     https://www.luogu.com.cn/problem/P1880
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9, maxn = 105, maxN = 205;

int n, N, a[maxN], pre[maxN], dp_max[maxn][maxN], dp_min[maxn][maxN], min_ans = INF, max_ans;

void loopToChain() {
    for (int i = 1; i < n; i++) {
        a[i + n] = a[i];
        pre[i + n] = pre[i + n - 1] + a[i + n];
    }
}

void DP() {
    for (int i = 2; i <= n; i++) {
        int const limit = N - i + 1;
        for (int j = 1; j <= limit; j++) {
            int sum = pre[j + i - 1] - pre[j - 1];
            int max_val = 0, min_val = INF;
            for (int k = 1; k <= i - 1; k++) {
                min_val = min(min_val, dp_min[k][j] + dp_min[i - k][j + k] + sum);
                max_val = max(max_val, dp_max[k][j] + dp_max[i - k][j + k] + sum);
            }
            dp_min[i][j] = min_val;
            dp_max[i][j] = max_val;
            if (i == n) {
                min_ans = min(min_ans, dp_min[i][j]);
                max_ans = max(max_ans, dp_max[i][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    loopToChain();
    N = 2 * n - 1;
    DP();
    cout << min_ans << '\n' << max_ans;
    return 0;
}
