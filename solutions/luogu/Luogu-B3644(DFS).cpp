// Problem:  Luogu B3644 【模板】拓扑排序 / 家谱树
// Link:     https://www.luogu.com.cn/problem/B3644
// Author:   nine19een
// Date:     2025-10-22
// Method:   DFS

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

int n;
bool vis[maxn];
vector<int> adj[maxn], topo;

void DFS(int idx) {
    vis[idx] = true;
    for (int p: adj[idx]) {
        if (!vis[p]) {
            DFS(p);
        }
    }
    topo.push_back(idx);
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
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int p: topo) {
        cout << p << " ";
    }
    return 0;
}
