// Problem:  Luogu P2895 [USACO08FEB] Meteor Shower S
// Link:     https://www.luogu.com.cn/problem/P2895
// Author:   nine19een
// Date:     2026-03-25

#include <bits/stdc++.h>
using namespace std;
constexpr int maxx = 310, inf = 1e9;

struct Meteor {
    int x, y, t;
};

int m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, f1stBurn[maxx][maxx];
bool vis[maxx][maxx], safe[maxx][maxx], safety;

void init() {
    for (int i = 0; i < maxx; ++i) {
        for (int j = 0; j < maxx; ++j) {
            safe[i][j] = true;
            f1stBurn[i][j] = inf;
        }
    }
}

bool inRange(int x, int y) {
    return x >= 0 && x <= 302 && y >= 0 && y <= 302;
}

void burn(int x, int y, int t) {
    safe[x][y] = false;
    f1stBurn[x][y] = t < f1stBurn[x][y] ? t : f1stBurn[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inRange(nx, ny)) {
            safe[nx][ny] = false;
            f1stBurn[nx][ny] = t < f1stBurn[nx][ny] ? t : f1stBurn[nx][ny];
        }
    }
}

void BFS() {
    queue<Meteor> q;
    if (!f1stBurn[0][0]) {
        return;
    }
    q.push({0, 0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y, ct = q.front().t;
        q.pop();
        if (safe[cx][cy]) {
            cout << ct;
            safety = true;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
            if (inRange(nx, ny) && f1stBurn[nx][ny] > nt && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny, nt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        burn(x, y, t);
    }
    BFS();
    if (!safety) {
        cout << -1;
    }
    return 0;
}
