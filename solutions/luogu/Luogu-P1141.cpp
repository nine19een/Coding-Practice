// Problem:  Luogu P1141 01迷宫
// Link:     https://www.luogu.com.cn/problem/P1141
// Author:   nine19een
// Date:     2026-03-25

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;

struct Node {
    int x, y;
};

int n, m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, cnt[maxn][maxn];
char maze[maxn][maxn];
bool vis[maxn][maxn];
vector<Node> ans;

bool available(int x, int y, int ox, int oy) {
    return x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y] && maze[x][y] != maze[ox][oy];
}

void CNT() {
    int tot = (int) ans.size();
    for (Node node: ans) {
        cnt[node.x][node.y] = tot;
    }
    ans.clear();
}

void BFS(int x, int y) {
    queue<Node> q;
    q.push(Node{x, y});
    ans.push_back(Node{x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (available(nx, ny, cx, cy)) {
                q.push(Node{nx, ny});
                ans.push_back(Node{nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    CNT();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                BFS(i, j);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cout << cnt[x][y] << '\n';
    }
    return 0;
}
