// Problem:  Luogu P4779 【模板】单源最短路径（标准版）
// Link:     https://www.luogu.com.cn/problem/P4779
// Author:   nine19een
// Date:     2025-12-20

#include<bits/stdc++.h>
using namespace std;

int const INF = 1e9 + 5;
int n, m, s;

struct Node {
    int idx, w;
};

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.w > b.w;
    }
};

void dijkstra(int s, vector<vector<Node> > &adj, vector<int> &dis, vector<bool> &vis,
              priority_queue<Node, vector<Node>, cmp> &pq) {
    dis[s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        Node top = pq.top();
        int u = top.idx;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (Node &node: adj[u]) {
            if (node.w + dis[u] < dis[node.idx]) {
                dis[node.idx] = node.w + dis[u];
                pq.push({node.idx, dis[node.idx]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    vector<vector<Node> > adj(n + 5);
    vector<int> dis(n + 5, INF);
    vector<bool> vis(n + 5, false);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<Node, vector<Node>, cmp> pq;
    dijkstra(s, adj, dis, vis, pq);
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}
