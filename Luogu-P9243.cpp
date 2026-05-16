// Problem:  Luogu P9242 [蓝桥杯 2023 省 B] 岛屿个数
// Link:     https://www.luogu.com.cn/problem/P9243
// Author:   nine19een
// Date:     2026-04-08

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 55;

struct Node {
    int x, y;
};

int t, m, n, cnt, dx[] = {1, 0, -1, 0, -1, -1, 1, 1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
bool vis[maxn][maxn], isIsland, vis_sea[maxn][maxn];
char maze[maxn][maxn];

void init() {
    memset(vis, 0, sizeof vis);
    cnt = 0;
}

bool inRange(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void DFS(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inRange(nx, ny) && !vis[nx][ny] && maze[nx][ny] == '1') {
            DFS(nx, ny);
        }
    }
}

void BFS(int x, int y) {
    queue<Node> q;
    q.push(Node{x, y});
    vis_sea[x][y] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y;
        q.pop();
        if (cx == 1 || cx == m || cy == 1 || cy == n) {
            isIsland = true;
            return;
        }
        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (inRange(nx, ny) && maze[nx][ny] == '0' && !vis_sea[nx][ny]) {
                q.push(Node{nx, ny});
                vis_sea[nx][ny] = true;
            }
        }
    }
}

void op() {
    init();
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> maze[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (maze[i][j] == '1' && !vis[i][j]) {
                DFS(i, j);
                isIsland = false;
                memset(vis_sea, 0, sizeof vis_sea);
                BFS(i, j);
                if (isIsland) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
