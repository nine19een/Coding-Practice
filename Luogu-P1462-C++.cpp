// Problem:  Luogu P1462 通往奥格瑞玛的道路
// Link:     https://www.luogu.com.cn/problem/P1462
// Author:   nine19een
// Date:     2025-12-21

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 1e4 + 5, INF = 1e18;

struct Node {
    int idx;
    ll w;
};

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.w > b.w;
    }
};

int n, m, B, f[maxn];
vector<vector<Node> > adj(maxn);
vector<ll> blood(maxn, INF);
bool vis[maxn];

bool check(int mid) {
    priority_queue<Node, vector<Node>, cmp> pq;
    memset(vis, 0, sizeof(vis));
    blood.assign(maxn, INF);
    blood[1] = 0;
    pq.push({1, 0});
    while (!pq.empty()) {
        int u = pq.top().idx;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (Node nd: adj[u]) {
            if (blood[nd.idx] > blood[u] + nd.w && f[nd.idx] <= mid) {
                blood[nd.idx] = blood[u] + nd.w;
                pq.push({nd.idx, blood[nd.idx]});
            }
        }
    }
    if (blood[n] > B) {
        return false;
    } else {
        return true;
    }
}

int find_min(int max_f) {
    ll l = max(f[1], f[n]), r = max_f + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (r == max_f + 1) {
        return -1;
    } else {
        return r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> B;
    ll max_f = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        max_f = max((ll) f[i], max_f);
    }
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int ans = find_min(max_f);
    if (ans == -1) {
        cout << "AFK";
    } else {
        cout << ans;
    }
    return 0;
}
