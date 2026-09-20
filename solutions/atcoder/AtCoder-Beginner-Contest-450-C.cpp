// Problem:  AtCoder Beginner Contest 450 C - Puddles
// Link:     https://atcoder.jp/contests/abc450/tasks/abc450_c
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;
constexpr int maxHW = 1e3 + 5;

struct Node {
    int x, y;
};

int h, w, cnt, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char maze[maxHW][maxHW];
bool vis[maxHW][maxHW];
vector<Node> white;

bool available(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w && !vis[x][y] && maze[x][y] == '.';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    white.reserve(maxHW * maxHW);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                white.push_back({i, j});
            }
        }
    }
    for (Node const &node: white) {
        if (!vis[node.x][node.y]) {
            bool edge = false;
            queue<Node> q;
            q.push(node);
            vis[node.x][node.y] = true;
            while (!q.empty()) {
                int cur_x = q.front().x, cur_y = q.front().y;
                q.pop();
                if (cur_x == 1 || cur_x == h || cur_y == 1 || cur_y == w) {
                    edge = true;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = cur_x + dx[i], ny = cur_y + dy[i];
                    if (available(nx, ny)) {
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            if (!edge) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
