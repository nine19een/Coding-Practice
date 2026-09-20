// Problem:  Luogu P3956 [NOIP 2017 普及组] 棋盘
// Link:     https://www.luogu.com.cn/problem/P3956
// Author:   nine19een
// Date:     2026-01-02

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005, maxm = 105, INF = 0x3f3f3f3f;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

struct Node {
    int x, y, color = 2, cost = INF;
    bool magic;
};

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

int n, m, ct[maxm][maxm][2];
Node a[maxm][maxm];

bool available(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= m;
}

void BFS() {
    priority_queue<Node, vector<Node>, cmp> pq;
    memset(ct, 0x3f, sizeof(ct));
    ct[1][1][0] = 0;
    pq.push({1, 1, a[1][1].color, 0, false});
    while (!pq.empty()) {
        Node t = pq.top();
        pq.pop();
        if (t.cost > ct[t.x][t.y][t.magic]) {
            continue;
        }
        for (int i = 0; i <= 3; i++) {
            int new_x = t.x + dx[i], new_y = t.y + dy[i];
            if (!available(new_x, new_y)) {
                continue;
            }
            if (a[new_x][new_y].color == t.color && ct[new_x][new_y][0] > t.cost) {
                ct[new_x][new_y][0] = t.cost;
                pq.push({new_x, new_y, t.color, t.cost, false});
                continue;
            }
            if (a[new_x][new_y].color != t.color && a[new_x][new_y].color != 2 && ct[new_x][new_y][0] > t.cost + 1) {
                ct[new_x][new_y][0] = t.cost + 1;
                pq.push({new_x, new_y, a[new_x][new_y].color, ct[new_x][new_y][0], false});
            }
            if (a[new_x][new_y].color == 2 && !t.magic && ct[new_x][new_y][1] > t.cost + 2) {
                ct[new_x][new_y][1] = t.cost + 2;
                pq.push({new_x, new_y, t.color, ct[new_x][new_y][1], true});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        a[x][y].color = c;
    }
    BFS();
    int ans = min(ct[m][m][0], ct[m][m][1]);
    cout << (ans == INF ? -1 : ans);
    return 0;
}
