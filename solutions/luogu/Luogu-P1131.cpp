// Problem:  Luogu P1131 [ZJOI2007] 时态同步
// Link:     https://www.luogu.com.cn/problem/P1131
// Author:   nine19een
// Date:     2026-02-22

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 5e5 + 5;

struct Node {
    int v, t;
};

int n, s;
ll dp[maxn], max_t[maxn];
vector<Node> adj[maxn];

void DP(int u, int fa) {
    int size_u = (int) adj[u].size();
    if (size_u == 1) {
        return;
    }
    ll max_time = 0;
    for (Node node: adj[u]) {
        if (node.v == fa) {
            continue;
        }
        DP(node.v, u);
        max_time = max(node.t + max_t[node.v], max_time);
    }
    max_t[u] = max_time;
    for (Node node: adj[u]) {
        if (node.v == fa) {
            continue;
        }
        dp[u] += dp[node.v] + (max_time - node.t - max_t[node.v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    adj[0].push_back({s, 0});
    adj[s].push_back({0, 0});
    DP(s, 0);
    cout << dp[s];
    return 0;
}
