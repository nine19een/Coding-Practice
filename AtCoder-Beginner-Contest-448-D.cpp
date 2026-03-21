// Problem:  AtCoder Beginner Contest 448 D - Integer-duplicated Path
// Link:     https://atcoder.jp/contests/abc448/tasks/abc448_d
// Author:   nine19een
// Date:     2026-03-07

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, a[maxn], ans[maxn];
vector<int> adj[maxn];
unordered_map<int, int> mp;

void dfs(int u, int fa, bool y) {
    mp[a[u]]++;
    ans[u] = y || mp[a[u]] > 1;
    for (int v: adj[u]) {
        if (v != fa) {
            dfs(v, u, ans[u]);
        }
    }
    mp[a[u]]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, false);
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}
