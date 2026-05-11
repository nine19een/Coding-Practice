// Problem:  蓝桥杯 2026 省 B F题 - 应急布线
// Link:     https://www.luogu.com.cn/problem/P16237
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, m, cnt;
vector<int> adj[maxn];
bool vis[maxn];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt++;
            BFS(i);
        }
    }
    int new_edges = cnt - 1;
    int mx = (new_edges * 2 + n - 1) / n;
    cout << new_edges << " " << mx;
    return 0;
}
