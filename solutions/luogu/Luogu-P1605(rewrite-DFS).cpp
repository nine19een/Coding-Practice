// Problem:  Luogu P1605 迷宫
// Link:     https://www.luogu.com.cn/problem/P1605
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, maze[10][10], cnt;
bool vis[10][10];

bool available(int x, int y) {
    return x <= n && x >= 1 && y <= m && y >= 1 && !maze[x][y] && !vis[x][y];
}

void DFS(int x, int y) {
    vis[x][y] = true;
    if (x == fx && y == fy) {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (available(nx, ny)) {
            DFS(nx, ny);
            vis[nx][ny] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; ++i) {
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    DFS(sx, sy);
    cout << cnt;
    return 0;
}
