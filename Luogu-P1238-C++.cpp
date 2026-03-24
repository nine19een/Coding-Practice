#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 20;

struct Node {
    int x, y;
};

int m, n, sx, sy, ex, ey, maze[maxn][maxn], dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
bool vis[maxn][maxn], have_ans;
vector<Node> ans;

void printAns() {
    for (Node node: ans) {
        cout << "(" << node.x << "," << node.y << ")";
        if (node.x != ex || node.y != ey) {
            cout << "->";
        };
    }
    cout << '\n';
}

bool available(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n && !vis[x][y] && maze[x][y] == 1;
}

void DFS(int x, int y) {
    vis[x][y] = true;
    ans.push_back(Node{x, y});
    if (x == ex && y == ey) {
        printAns();
        have_ans = true;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (available(nx, ny)) {
            DFS(nx, ny);
            vis[nx][ny] = false;
            ans.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ans.reserve(maxn * maxn);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> maze[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    DFS(sx, sy);
    if (!have_ans) {
        cout << -1;
    }
    return 0;
}
