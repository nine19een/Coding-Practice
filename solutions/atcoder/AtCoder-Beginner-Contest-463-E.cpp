// Problem:  AtCoder Beginner Contest 463 E - Roads and Gates
// Link:     https://atcoder.jp/contests/abc463/tasks/abc463_e
// Author:   nine19een
// Date:     2026-06-20

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 4e5 + 5, INF = 1e18 + 10;

struct Node {
    int v;
    ll w;

    bool operator<(const Node &other) const {
        return w > other.w;
    }
};

vector<Node> adj[maxn];
int n, m;
ll y, x[maxn], dis[maxn];
bool vis[maxn];

void Dijkstra() {
    priority_queue<Node> pq;
    dis[1] = 0;
    pq.push({1, 0});
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (Node nd: adj[u]) {
            int v = nd.v;
            ll w = nd.w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

void init() {
    int vir = n + 1;
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        adj[i].push_back({vir, x[i]});
        adj[vir].push_back({i, x[i] + y});
    }
    dis[n + 1] = INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> y;
    for (int i = 1; i <= m; ++i) {
        int ui, vi, ti;
        cin >> ui >> vi >> ti;
        adj[ui].push_back({vi, ti});
        adj[vi].push_back({ui, ti});
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    init();
    Dijkstra();
    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}
