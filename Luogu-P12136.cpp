// Problem:  Luogu P12136 [蓝桥杯 2025 省 B] 生产车间
// Link:     https://www.luogu.com.cn/problem/P12136
// Author:   nine19een
// Date:     2026-04-05

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;

vector<int> adj[maxn];
int n, w[maxn];
bitset<maxn> dp[maxn], nt;

void DFS(int u, int f) {
    dp[u][0] = true;
    if (adj[u].size() == 1 && u != 1) {
        dp[u][w[u]] = true;
        return;
    }
    for (int v: adj[u]) {
        if (v != f) {
            DFS(v, u);
            nt.reset();
            for (int i = 0; i <= w[v]; ++i) {
                if (dp[v][i]) {
                    nt |= (dp[u] << i);
                }
            }
            for (int i = w[u] + 1; i <= 1000; ++i) {
                nt[i] = false;
            }
            dp[u] = nt;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    int ans = 0;
    for (int i = 0; i <= w[1]; ++i) {
        if (dp[1][i]) {
            ans = i;
        }
    }
    cout << ans;
}