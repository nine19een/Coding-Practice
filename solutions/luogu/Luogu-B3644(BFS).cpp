// Problem:  Luogu B3644 【模板】拓扑排序 / 家谱树
// Link:     https://www.luogu.com.cn/problem/B3644
// Author:   nine19een
// Date:     2025-10-22
// Method:   BFS

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

int in_degree[maxn], n;
vector<int> adj[maxn], topo;

void BFS() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node_f = q.front();
        topo.push_back(node_f);
        q.pop();
        for (int p: adj[node_f]) {
            in_degree[p]--;
            if (!in_degree[p]) {
                q.push(p);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    topo.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        while (1) {
            int node;
            cin >> node;
            if (!node) {
                break;
            }
            adj[i].push_back(node);
            in_degree[node]++;
        }
    }
    BFS();
    for (int p: topo) {
        cout << p << " ";
    }
    return 0;
}
