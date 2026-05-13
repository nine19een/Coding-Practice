// Problem:  Luogu P1807 最长路
// Link:     https://www.luogu.com.cn/problem/P1807
// Author:   nine19een
// Date:     2025-12-22

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1505, INF = 1e18;

struct Edge {
    ll to, w;
};

ll n, m;
bool vis[maxn];
vector<ll> dp(maxn, -INF);
vector<Edge> adj[maxn];

ll DFS(ll u) {
    if (vis[u]) {
        return dp[u];
    };
    vis[u] = true;
    if (u == n) {
        dp[u] = 0;
        return dp[u];
    }
    for (const auto &e: adj[u]) {
        ll v = e.to, w = e.w;
        ll cur_len = DFS(v);
        if (cur_len != -INF) {
            dp[u] = max(dp[u], cur_len + w);
        }
    }
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    ll ans = DFS(1);
    if (ans == -INF) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
