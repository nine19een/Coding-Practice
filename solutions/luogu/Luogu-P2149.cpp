// Problem:  Luogu P2149 [SDOI2009] Elaxia的路线
// Link:     https://www.luogu.com.cn/problem/P2149
// Author:   nine19een
// Date:     2025-12-22

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1505, INF = 1e9;

struct Edge {
    int to, w;
};

struct Node {
    int v, dis;
};

struct cmp {
    bool operator()(const Node &n1, const Node &n2) {
        return n1.dis > n2.dis;
    }
};

int n, m, s1, s2, t1, t2, len1, len2;
vector<int> dis1_s(maxn, INF), dis2_s(maxn, INF), dis1_t(maxn, INF), dis2_t(maxn, INF);
bool vis[maxn];
vector<Edge> adj[maxn], adj_same[maxn], adj_diff[maxn];

void Dijkstra(int s, vector<int> &d) {
    memset(vis, 0, sizeof(vis));
    priority_queue<Node, vector<Node>, cmp> pq;
    d[s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.v;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (const auto &e: adj[u]) {
            int v = e.to, w = e.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
}

void Select() {
    for (int u = 1; u <= n; u++) {
        for (const auto &e: adj[u]) {
            int v = e.to, w = e.w;
            if (dis1_s[u] + w + dis1_t[v] == len1) {
                if (dis2_s[u] + w + dis2_t[v] == len2) {
                    adj_same[u].push_back({v, w});
                }
                if (dis2_s[v] + w + dis2_t[u] == len2) {
                    adj_diff[u].push_back({v, w});
                }
            }
        }
    }
}

int DFS(int u, vector<Edge> a[], vector<int> &dp) {
    if (dp[u] != -1) {
        return dp[u];
    }
    dp[u] = 0;
    for (const auto &e: a[u]) {
        int v = e.to, w = e.w;
        dp[u] = max(dp[u], DFS(v, a, dp) + w);
    }
    return dp[u];
}

int findMax() {
    int max_len1 = 0, max_len2 = 0;
    vector<int> dp(maxn, -1);
    for (int u = 1; u <= n; u++) {
        max_len1 = max(DFS(u, adj_same, dp), max_len1);
    }
    dp.assign(maxn, -1);
    for (int u = 1; u <= n; u++) {
        max_len2 = max(DFS(u, adj_diff, dp), max_len2);
    }
    return max(max_len1, max_len2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s1 >> t1 >> s2 >> t2;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(s1, dis1_s);
    Dijkstra(t1, dis1_t);
    Dijkstra(s2, dis2_s);
    Dijkstra(t2, dis2_t);
    len1 = dis1_s[t1];
    len2 = dis2_s[t2];
    Select();
    cout << findMax();
    return 0;
}
