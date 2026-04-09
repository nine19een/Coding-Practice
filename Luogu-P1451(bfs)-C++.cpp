// Problem:  Luogu P1451 求细胞数量
// Link:     https://www.luogu.com.cn/problem/P1451
// Author:   nine19een
// Date:     2026-04-09
// Method:   BFS

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;

struct Node {
    int x, y;
};

int n, m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, cnt;
char maze[maxn][maxn];
bool vis[maxn][maxn];

bool available(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && maze[x][y] >= '1' && maze[x][y] <= '9';
}

void BFS(int x, int y) {
    queue<Node> q;
    q.push(Node{x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (available(nx, ny)) {
                vis[nx][ny] = true;
                q.push(Node{nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j] && maze[i][j] != '0') {
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
