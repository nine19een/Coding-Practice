// Problem:  Luogu P1902 刺杀大使
// Link:     https://www.luogu.com.cn/problem/P1902
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int n, m, maze[maxn][maxn], max_damage;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool vis[maxn][maxn];

bool Check(int x, int y, int limit) {
    return x > 1 && x <= n && y >= 1 && y <= m && maze[x][y] <= limit && !vis[x][y];
}

void DFS(int x, int y, int limit, bool &flag) {
    if (x == n || flag) {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (Check(nx, ny, limit)) {
            vis[nx][ny] = true;
            DFS(nx, ny, limit, flag);
        }
    }
}

bool Available(int limit) {
    bool flag = false;
    for (int i = 1; i <= m; ++i) {
        if (maze[2][i] <= limit) {
            vis[2][i] = true;
            DFS(2, i, limit, flag);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}

int Binary() {
    int l = 0, r = max_damage + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!Available(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
        memset(vis, false, sizeof vis);
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
            max_damage = max(max_damage, maze[i][j]);
        }
    }
    cout << Binary();
    return 0;
}
