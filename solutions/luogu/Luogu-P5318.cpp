// Problem:  Luogu P5318 【深基18.例3】查找文献
// Link:     https://www.luogu.com.cn/problem/P5318
// Author:   nine19een
// Date:     2025-10-22

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;

int n, m;
vector<int> node[maxn];
bool vis[maxn];

void DFS(int idx) {
    vis[idx] = true;
    cout << idx << " ";
    for (int p: node[idx]) {
        if (!vis[p]) {
            DFS(p);
        }
    }
}

void BFS() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int f_idx = q.front();
        cout << f_idx << " ";
        q.pop();
        for (int p: node[f_idx]) {
            if (!vis[p]) {
                q.push(p);
                vis[p] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int idx, out_d;
        cin >> idx >> out_d;
        node[idx].push_back(out_d);
    }
    for (int i = 1; i <= n; ++i) {
        sort(node[i].begin(), node[i].end());
    }
    DFS(1);
    memset(vis, 0, sizeof(vis));
    cout << '\n';
    BFS();
    return 0;
}
