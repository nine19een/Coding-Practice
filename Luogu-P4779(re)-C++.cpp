// Problem:  Luogu P4779 【模板】单源最短路径（标准版）
// Link:     https://www.luogu.com.cn/problem/P4779
// Author:   nine19een
// Date:     2026-04-09

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5, INF = 1e9 + 5;

struct Node {
    int u, w;

    bool operator >(const Node &other) const {
        return w > other.w;
    }
};

int n, m, s, dis[maxn];
bool vis[maxn];
vector<Node> adj[maxn];

void init() {
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
}

void Dijkstra() {
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    dis[s] = 0;
    pq.push(Node{s, 0});
    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (Node nd: adj[u]) {
            int v = nd.u;
            if (dis[u] + nd.w < dis[v]) {
                dis[v] = dis[u] + nd.w;
                pq.push(Node{v, dis[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Node{v, w});
    }
    init();
    Dijkstra();
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}
