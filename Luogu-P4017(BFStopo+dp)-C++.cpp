// Problem:  Luogu P4017 最大食物链计数
// Link:     https://www.luogu.com.cn/problem/P4017
// Author:   nine19een
// Date:     2025-10-22
// Method:   BFS拓扑排序+DP

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 5e3 + 5, hash_num = 80112002;

struct Node {
    ll in_degree, cnt;
    vector<ll> out;
};

ll n, m, ans;
Node node[maxn];

void BFS_DP() {
    queue<ll> q;
    for (ll i = 1; i <= n; ++i) {
        if (!node[i].in_degree) {
            node[i].cnt++;
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll q_f = q.front();
        q.pop();
        if (node[q_f].out.empty()) {
            ans = (ans + (node[q_f].cnt % hash_num)) % hash_num;
            continue;
        }
        for (ll p: node[q_f].out) {
            node[p].cnt = ((node[p].cnt % hash_num) + (node[q_f].cnt % hash_num)) % hash_num;
            node[p].in_degree--;
            if (!node[p].in_degree) {
                q.push(p);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        node[x].out.push_back(y);
        node[y].in_degree++;
    }
    BFS_DP();
    cout << ans;
    return 0;
}
