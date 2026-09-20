// Problem:  Luogu P1162 填涂颜色
// Link:     https://www.luogu.com.cn/problem/P1162
// Author:   nine19een
// Date:     2025-10-13
// Method:   由外向内BFS

#include <bits/stdc++.h>
using namespace std;
int const maxn = 35, maxm = 35 * 35;

struct Point{
    int x, y;
};

int n, ground[maxn][maxn];

bool available(Point check_p) {
    return (check_p.x < 1 || check_p.x > n || check_p.y < 1 || check_p.y > n || ground[check_p.x][check_p.y] == 1 || ground[check_p.x][check_p.y] == -1) ? false : true;
}

void bfs(Point p, queue<Point> &q) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    q.push(p);
    ground[p.x][p.y] = -1;
    while (!q.empty()) {
        Point now_p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            Point new_p = {now_p.x + dx[i], now_p.y + dy[i]};
            if (available(new_p)) {
                ground[new_p.x][new_p.y] = -1;
                q.push(new_p);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ground[i][j];
        }
    }
    queue<Point> q;
    for (int i = 1; i <= n; i += n - 1) {
        for (int j = 1; j <= n; ++j) {
            if (ground[i][j] == 0) {
                bfs({i, j}, q);
            }
        }
    }
    for (int j = 1; j <= n; j += n - 1) {
        for (int i = 2; i < n; ++i) {
            if (ground[i][j] == 0) {
                bfs({i, j}, q);
            }
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            switch (ground[x][y]) {
                case -1: {
                    cout << 0 << " ";
                    break;
                }
                case 0: {
                    cout << 2 << " ";
                    break;
                }
                case 1: {
                    cout << 1 << " ";
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}