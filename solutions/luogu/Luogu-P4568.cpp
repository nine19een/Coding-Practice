// Problem:  Luogu P4568 [JLOI2011] 飞行路线
// Link:     https://www.luogu.com.cn/problem/P4568
// Author:   nine19een
// Date:     2025-12-21

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5, maxk = 15, INF = 1e9;

struct City {
    int idx, w, step;
};

struct cmp {
    bool operator()(const City &a, const City &b) {
        return a.w > b.w;
    }
};

int n, m, K, s, t;
bool vis[maxn][maxk];
vector<vector<int> > cost(maxn, vector<int>(maxk, INF));
vector<vector<City> > adj(maxn);

void Dijkstra(int s, int t) {
    priority_queue<City, vector<City>, cmp> pq;
    cost[s][0] = 0;
    pq.push({s, 0, 0});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.idx, k = top.step;
        if (vis[u][k]) {
            continue;
        }
        vis[u][k] = true;
        for (auto ct: adj[u]) {
            if (cost[ct.idx][k] > cost[u][k] + ct.w) {
                cost[ct.idx][k] = cost[u][k] + ct.w;
                pq.push({ct.idx, cost[ct.idx][k], k});
            }
            if (k < K && cost[ct.idx][k + 1] > cost[u][k]) {
                cost[ct.idx][k + 1] = cost[u][k];
                pq.push({ct.idx, cost[ct.idx][k + 1], k + 1});
            }
        }
    }
}

int Cheapest(int t) {
    int min_price = INF;
    for (int i = 0; i <= K; ++i) {
        min_price = min(min_price, cost[t][i]);
    }
    return min_price;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> K >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c, 0});
        adj[b].push_back({a, c, 0});
    }
    Dijkstra(s, t);
    cout << Cheapest(t);
    return 0;
}
