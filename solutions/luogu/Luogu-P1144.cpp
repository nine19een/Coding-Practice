// Problem:  Luogu P1144 最短路计数
// Link:     https://www.luogu.com.cn/problem/P1144
// Author:   nine19een
// Date:     2025-12-20

#include<bits/stdc++.h>
using namespace std;

const int MOD = 100003, maxn = 1e6 + 5;

int n, m, dis[maxn], cnt[maxn];
bool vis[maxn];
vector<vector<int> > adj(maxn);

void BFS() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    cnt[1]++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int p: adj[u]) {
            if (!vis[p]) {
                vis[p] = true;
                dis[p] = dis[u] + 1;
                cnt[p] = cnt[u];
                q.push(p);
            } else if (vis[p] && dis[p] == dis[u] + 1) {
                cnt[p] = (cnt[p] + cnt[u]) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS();
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << '\n';
    }
    return 0;
}
