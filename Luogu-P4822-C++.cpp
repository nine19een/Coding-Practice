// Problem:  Luogu P4822 [BJWC2012] 冻结
// Link:     https://www.luogu.com.cn/problem/P4822
// Author:   nine19een
// Date:     2025-12-20

#include<bits/stdc++.h>
using namespace std;

int const INF = 1e9 + 5, maxn = 55;

struct Node {
    int idx, time, step;
};

struct cmp {
    bool operator()(Node const &a, Node const &b) {
        return a.time > b.time;
    }
};

int n, m, K;
bool vis[maxn][maxn];
vector<vector<int> > dis(maxn, vector<int>(maxn, INF));
vector<vector<Node> > adj(maxn);

void dijkstra() {
    dis[1][0] = 0;
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        Node top = pq.top();
        int u = top.idx, k = top.step;
        pq.pop();
        if (vis[u][k]) {
            continue;
        }
        vis[u][k] = true;
        for (Node node: adj[u]) {
            if (node.time + dis[u][k] < dis[node.idx][k]) {
                dis[node.idx][k] = node.time + dis[u][k];
                pq.push({node.idx, dis[node.idx][k], k});
            }
        }
        if (k < K) {
            for (Node node: adj[u]) {
                if (node.time / 2 + dis[u][k] < dis[node.idx][k + 1]) {
                    dis[node.idx][k + 1] = node.time / 2 + dis[u][k];
                    pq.push({node.idx, dis[node.idx][k + 1], k + 1});
                }
            }
        }
    }
}

int find_shortest() {
    int ans = INF;
    for (int i = 0; i <= K; ++i) {
        ans = min(dis[n][i], ans);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> K;
    for (int i = 1; i <= m; ++i) {
        int a, b, time;
        cin >> a >> b >> time;
        adj[a].push_back({b, time, 0});
        adj[b].push_back({a, time, 0});
    }
    dijkstra();
    cout << find_shortest();
    return 0;
}
