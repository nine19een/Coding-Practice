// Problem:  Luogu P3174 [HAOI2009] 毛毛虫
// Link:     https://www.luogu.com.cn/problem/P3174
// Author:   nine19een
// Date:     2026-03-11

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 300005;

int n, m, dp[maxn], max_worm;
vector<int> adj[maxn];

void DP(int u, int fa) {
    int max1 = 0, max2 = 0;
    int son_cnt = 0;
    for (int v: adj[u]) {
        if (v != fa) {
            son_cnt++;
            DP(v, u);
            if (dp[v] > max1) {
                max2 = max1;
                max1 = dp[v];
            } else if (dp[v] > max2) {
                max2 = dp[v];
            }
        }
    }
    int worm = max1 + max2 + 1;;
    if (son_cnt >= 2) {
        worm += son_cnt - 2;
    }
    if (u != 1) {
        worm++;
    }
    max_worm = max(max_worm, worm);
    dp[u] = max1 + 1;
    if (son_cnt >= 1) {
        dp[u] += son_cnt - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DP(1, 0);
    cout << max_worm;
    return 0;
}
