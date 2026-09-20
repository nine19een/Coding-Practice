// Problem:  Luogu P4551 最长异或路径
// Link:     https://www.luogu.com.cn/problem/P4551
// Author:   nine19een
// Date:     2026-01-27

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxN = 31e5 + 5;

struct Node {
    int v, w;
};

int n, D[maxn], trie[maxN][2], ans = 0;
vector<Node> adj[maxn];

void DFS(int u, int w, int fa) {
    D[u] = D[fa] ^ w;
    for (Node nd: adj[u]) {
        if (nd.v != fa) {
            DFS(nd.v, nd.w, u);
        }
    }
}

inline void Insert(int x, int &idx) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int v = x >> i & 1;
        if (!trie[p][v]) {
            trie[p][v] = ++idx;
        }
        p = trie[p][v];
    }
}

inline void Query(int x) {
    int sum = 0, p = 0;
    for (int i = 30; i >= 0; i--) {
        int v = x >> i & 1;
        if (trie[p][v ^ 1]) {
            sum |= 1 << i;
            p = trie[p][v ^ 1];
        } else {
            p = trie[p][v];
        }
    }
    ans = max(ans, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    DFS(1, 0, 0);
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        Insert(D[i], idx);
    }
    for (int i = 1; i <= n; i++) {
        Query(D[i]);
    }
    cout << ans;
    return 0;
}