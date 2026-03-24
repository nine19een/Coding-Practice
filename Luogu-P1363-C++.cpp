#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1505;

struct Node {
    int x, y;

    bool operator==(const Node &node) const {
        return x == node.x && y == node.y;
    }

    bool operator!=(const Node &node) const {
        return x != node.x || y != node.y;
    }
};

int m, n, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char maze[maxn][maxn];
bool flag;
Node vis[maxn][maxn];

int R(int num, int mod) {
    int r = (num % mod + mod) % mod;
    return (!r ? mod : r);
}

void DFS(int x, int y) {
    int rx = R(x, n), ry = R(y, m);
    if (maze[rx][ry] == '#' || vis[rx][ry] == Node{x, y}) {
        return;
    }
    if (vis[rx][ry] == Node{0, 0}) {
        vis[rx][ry] = {x, y};
    } else {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        DFS(nx, ny);
        if (flag) {
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        Node s = {0, 0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    s = {i, j};
                }
            }
        }
        DFS(s.x, s.y);
        if (flag) {
            cout << "Yes" << '\n';
            flag = false;
        } else {
            cout << "No" << '\n';
        }
        memset(vis, 0, sizeof vis);
    }
    return 0;
}
