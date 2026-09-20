// Luogu P4017 - 最大食物链计数
// https://www.luogu.com.cn/problem/P4017
// Method: BFS 拓扑排序 + DP

#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 80112002, maxn = 5e3 + 5;

int n, m, in[maxn], dp[maxn], ans;
vector<int> adj[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> v >> u;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (adj[u].empty()) {
            ans = (ans + dp[u]) % MOD;
            continue;
        }
        for (int v: adj[u]) {
            dp[v] = (dp[u] + dp[v]) % MOD;
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
    cout << ans;
    return 0;
}