// Luogu P1443 - 马的遍历
// https://www.luogu.com.cn/problem/P1443

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 405;

int n, m, sx, sy, grid[maxn][maxn], dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

struct Node {
    int x, y, step;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(grid, -1, sizeof(grid));
    cin >> n >> m >> sx >> sy;
    queue<Node> q;
    q.push(Node{sx, sy, 0});
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        if (grid[t.x][t.y] == -1) {
            grid[t.x][t.y] = t.step;
            for (int i = 0; i < 8; ++i) {
                int nx = t.x + dx[i], ny = t.y + dy[i];
                if (inRange(nx, ny)) {
                    q.push(Node{nx, ny, t.step + 1});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}