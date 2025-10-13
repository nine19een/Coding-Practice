// Problem:  Luogu P1162 填涂颜色
// Link:     https://www.luogu.com.cn/problem/P1162
// Author:   nine19een
// Date:     2025-10-13

#include <bits/stdc++.h>
using namespace std;
int const maxn = 35, maxm = 35 * 35;

struct Point{
    int x, y;
};

int n, ground[maxn][maxn];
bool visited[maxn][maxn], ifPaint = true;;
vector<Point> in_queue;

bool available(Point check_p) {
    return (check_p.x < 1 || check_p.x > n || check_p.y < 1 || check_p.y > n || ground[check_p.x][check_p.y] == 1 || visited[check_p.x][check_p.y] == true) ? false : true;
}

void bfs(Point p, queue<Point> &q, vector<Point> &in_queue) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    q.push(p);
    in_queue.push_back(p);
    while (!q.empty()) {
        Point now_p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            Point new_p = {now_p.x + dx[i], now_p.y + dy[i]};
            if (available(new_p)) {
                visited[new_p.x][new_p.y] = true;
                q.push(new_p);
                in_queue.push_back(new_p);
                ifPaint = (new_p.x == 1 || new_p.y == 1 || new_p.x == n || new_p.y == n || ifPaint == false) ? false : true;
            }
        }
    }
    if (ifPaint) {
        for (Point point : in_queue) {
            ground[point.x][point.y] = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    in_queue.reserve(maxm);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ground[i][j];
        }
    }
    queue<Point> q;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < n; ++j) {
            if (ground[i][j] == 1 || visited[i][j]) {
                continue;
            }
            bfs({i, j}, q, in_queue);
            in_queue.clear();
            if (ifPaint) {
                for (int x = 1; x <= n; ++x) {
                    for (int y = 1; y <= n; ++y) {
                        cout << ground[x][y] << " ";
                    }
                    cout << '\n';
                }
                return 0;
            }
            ifPaint = true;
        }
    }
    return 0;
}
