#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1505;

struct Node {
    int x, y;
};

int m, n, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char maze[maxn][maxn];
bool vis[maxn][maxn];

bool available(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void DFS(int x, int y) {

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        Node s;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    s = {i, j};
                }
                DFS(s.x, s.y);
            }
        }

    }
    return 0;
}