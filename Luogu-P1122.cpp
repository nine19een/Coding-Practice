// Problem:  Luogu P1122 最大子树和
// Link:     https://www.luogu.com.cn/problem/P1122
// Author:   nine19een
// Date:     2026-01-30

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 16005;

int n, dp[maxn], max_beauty = INT_MIN;
vector<int> adj[maxn];

void DFS(int u, int f) {
    for (int v: adj[u]) {
        if (v != f) {
            DFS(v, u);
            dp[u] = max(dp[u], dp[u] + dp[v]);
        }
    }
    max_beauty = max(max_beauty, dp[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    cout << max_beauty;
    return 0;
}
