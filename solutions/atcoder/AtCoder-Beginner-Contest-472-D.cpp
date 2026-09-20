// Problem:  AtCoder Beginner Contest 472 D - Bomber Mad
// Link:     https://atcoder.jp/contests/abc472/tasks/abc472_d
// Author:   nine19een
// Date:     2026-08-22

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e5 + 25;

struct Node {
    int x, y, r;
};

int h, w, k, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, ans;
bool boom_h[maxn], boom_w[maxn];
vector<pair<int, int> > s;

bool available(int x, int y, const vector<vector<char> > &grid) {
    return x >= 1 && x <= h && y >= 1 && y <= w && grid[x][y] == '.';
}

void BFS(const vector<vector<char> > &grid, vector<vector<bool> > &vis) {
    queue<Node> q;
    for (pair p: s) {
        int sx = p.first, sy = p.second;
        vis[sx][sy] = true;
        q.push({sx, sy, k});
    }
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y, cr = q.front().r;
        q.pop();
        int nr = cr - 1;
        if (nr < 0) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (available(nx, ny, grid) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny, nr});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> k;
    vector<vector<char> > grid(h + 5, vector<char>(w + 5, 0));
    vector<vector<bool> > vis(h + 5, vector<bool>(w + 5, false));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                boom_h[i] = true;
                boom_w[j] = true;
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        if (boom_h[i]) {
            continue;
        }
        for (int j = 1; j <= w; ++j) {
            if (boom_w[j]) {
                continue;
            }
            s.emplace_back(i, j);
        }
    }
    BFS(grid, vis);
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (vis[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
