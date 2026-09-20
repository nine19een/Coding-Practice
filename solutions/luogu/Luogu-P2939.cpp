// Problem:  Luogu P2939 [USACO09FEB] Revamping Trails G
// Link:     https://www.luogu.com.cn/problem/P2939
// Author:   nine19een
// Date:     2025-12-21

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 1e4 + 5, maxk = 25, INF = 1e18;

struct path {
    int to;
    ll w;
};

struct farm {
    int v, k;
    ll dis;
};

struct cmp {
    bool operator()(const farm &a, const farm &b) {
        return a.dis > b.dis;
    }
};

int n, m, K;
vector<vector<path> > adj(maxn);
vector<vector<ll> > dis(maxn, vector<ll>(maxk, INF));
bool vis[maxn][maxk];

void Dijkstra() {
    priority_queue<farm, vector<farm>, cmp> pq;
    dis[1][0] = 0;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        int u = pq.top().v, k = pq.top().k;
        pq.pop();
        if (vis[u][k]) {
            continue;
        }
        vis[u][k] = true;
        for (const auto &p: adj[u]) {
            int v = p.to;
            if (dis[v][k] > dis[u][k] + p.w) {
                dis[v][k] = dis[u][k] + p.w;
                pq.push({v, k, dis[v][k]});
            }
            if (k < K && dis[v][k + 1] > dis[u][k]) {
                dis[v][k + 1] = dis[u][k];
                pq.push({v, k + 1, dis[v][k + 1]});
            }
        }
    }
}

ll ShortestPath() {
    ll ans = INF;
    for (int i = 0; i <= K; ++i) {
        ans = min(ans, dis[n][i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> K;
    for (int i = 1; i <= m; ++i) {
        int p1, p2, t;
        cin >> p1 >> p2 >> t;
        adj[p1].push_back({p2, t});
        adj[p2].push_back({p1, t});
    }
    Dijkstra();
    cout << ShortestPath();
    return 0;
}
