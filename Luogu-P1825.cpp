// Problem:  Luogu P1825 [USACO11OPEN] Corn Maze S
// Link:     https://www.luogu.com.cn/problem/P1825
// Author:   nine19een
// Date:     2026-03-25

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 305;

struct Node {
    int x, y, t;

    bool operator==(const Node &n) const {
        return x == n.x && y == n.y;
    }

    bool operator!=(const Node &n) const {
        return x != n.x || y != n.y;
    }
};

int n, m, sx, sy, ex, ey, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char maze[maxn][maxn];
bool vis[maxn][maxn];
vector<Node> portal[30];

bool isLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

bool available(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && maze[x][y] != '#';
}

void transfer(int &x, int &y) {
    for (Node node: portal[maze[x][y] - 'A']) {
        if (node != Node{x, y}) {
            x = node.x, y = node.y;
            break;
        }
    }
}

void BFS() {
    queue<Node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y, ct = q.front().t;
        q.pop();
        if (cx == ex && cy == ey) {
            cout << ct;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (available(nx, ny)) {
                if (isLetter(maze[nx][ny])) {
                    transfer(nx, ny);
                }
                if (!vis[nx][ny]) {
                    q.push({nx, ny, ct + 1});
                    vis[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                sx = i, sy = j;
            }
            if (maze[i][j] == '=') {
                ex = i, ey = j;
            }
            if (isLetter(maze[i][j])) {
                portal[maze[i][j] - 'A'].push_back({i, j});
            }
        }
    }
    BFS();
    return 0;
}
