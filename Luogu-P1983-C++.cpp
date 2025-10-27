// Problem:  Luogu P1983 [NOIP 2013 普及组] 车站分级
// Link:     https://www.luogu.com.cn/problem/P1983
// Author:   nine19een
// Date:     2025-10-27

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e3 + 5, maxm = 1e3 + 5;

struct Node {
    int dp, indegree;
    vector<int> adj;
};

bool vis[maxm];
int n, m, cnt_virtual = 1001;
Node node[maxn];

void buildANDreset(int left, int right) {
    for (int i = left; i <= right; i++) {
        if (!vis[i]) {
            node[cnt_virtual].adj.push_back(i);
            node[i].indegree++;
        }
        vis[i] = false;
    }
}

void build_adj() {
    int s;
    cin >> s;
    int left, right;
    for (int j = 1; j <= s; j++) {
        int num;
        cin >> num;
        vis[num] = true;
        node[num].adj.push_back(cnt_virtual);
        node[cnt_virtual].indegree++;
        if (j == 1) {
            left = num;
        }
        if (j == s) {
            right = num;
            buildANDreset(left, right);
        }
    }
    cnt_virtual++;
}

void Kahn() {
    for (int i = 1; i <= n; i++) {
        node[i].dp = 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!node[i].indegree) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int p: node[front].adj) {
            node[p].indegree--;
            if (!node[p].indegree) {
                node[p].dp = (p <= 1000) ? max(node[p].dp, node[front].dp + 1) : max(node[p].dp, node[front].dp);
                q.push(p);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, node[i].dp);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (m--) {
        build_adj();
    }
    Kahn();
    return 0;
}
