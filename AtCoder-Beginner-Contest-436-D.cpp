// Problem:  AtCoder Beginner Contest 436 D - Teleport Maze
// Link:     https://atcoder.jp/contests/abc436/tasks/abc436_d
// Author:   nine19een
// Date:     2025-12-13

#include<bits/stdc++.h>
using namespace std;
const int MAXH = 1005;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct Point {
    char c;
    bool vis;
    int cnt;
};

int h, w;
vector<pair<int, int> > letter[26];
Point p[MAXH][MAXH];
bool flag, used[26];

bool available(int x, int y) {
    return x <= h && x >= 1 && y <= w && y >= 1 && !p[x][y].vis && p[x][y].c != '#';
}

bool isLetter(int x, int y) {
    return p[x][y].c >= 'a' && p[x][y].c <= 'z';
}

void BFS() {
    queue<pair<int, int> > q;
    q.push({1, 1});
    p[1][1].vis = true;
    p[1][1].cnt = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == h && y == w) {
            cout << p[x][y].cnt;
            flag = true;
            return;
        }
        if (isLetter(x, y) && !used[p[x][y].c - 'a']) {
            used[p[x][y].c - 'a'] = true;
            for (pair<int, int> l: letter[p[x][y].c - 'a']) {
                int nx = l.first, ny = l.second;
                if (!p[nx][ny].vis) {
                    p[nx][ny].vis = true;
                    p[nx][ny].cnt = p[x][y].cnt + 1;
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (available(nx, ny)) {
                p[nx][ny].vis = true;
                p[nx][ny].cnt = p[x][y].cnt + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> p[i][j].c;
            if (isLetter(i, j)) {
                letter[p[i][j].c - 'a'].push_back({i, j});
            }
        }
    }
    BFS();
    if (!flag) {
        cout << -1;
    }
}
