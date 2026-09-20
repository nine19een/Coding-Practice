// Problem:  Luogu P1379 八数码难题
// Link:     https://www.luogu.com.cn/problem/P1379
// Author:   nine19een
// Date:     2026-03-26

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll target = 123804765;

struct State {
    int board[5][5];
    int cnt, x0, y0;
};

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
State initial_s;
unordered_set<ll> vis;

ll getHash(int a[5][5]) {
    ll val = 0, base = 1;
    for (int i = 3; i >= 1; --i) {
        for (int j = 3; j >= 1; --j) {
            val += a[i][j] * base;
            base *= 10;
        }
    }
    return val;
}

bool inRange(int nx, int ny) {
    return nx >= 1 && nx <= 3 && ny >= 1 && ny <= 3;
}

void cpyBoard(int a[5][5], int b[5][5]) {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            b[i][j] = a[i][j];
        }
    }
}

State next_state(int x0, int y0, int nx, int ny, int cpy[5][5], int cnt) {
    State ns;
    swap(cpy[nx][ny], cpy[x0][y0]);
    swap(nx, x0);
    swap(ny, y0);
    cpyBoard(cpy, ns.board);
    ns.x0 = x0, ns.y0 = y0;
    ns.cnt = cnt + 1;
    return ns;
}

void BFS() {
    queue<State> q;
    q.push(initial_s);
    vis.insert(getHash(initial_s.board));
    while (!q.empty()) {
        State s = q.front();
        q.pop();
        if (getHash(s.board) == target) {
            cout << s.cnt;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = s.x0 + dx[i], ny = s.y0 + dy[i];
            if (!inRange(nx, ny)) {
                continue;
            }
            int cpy[5][5];
            cpyBoard(s.board, cpy);
            State ns = next_state(s.x0, s.y0, nx, ny, cpy, s.cnt);
            ll hash = getHash(ns.board);
            if (!vis.count(hash)) {
                vis.insert(hash);
                q.push(ns);
            }
        }
    }
}

State transfer(ll n) {
    State s;
    s.cnt = 0, s.x0 = 0, s.y0 = 0;
    for (int i = 3; i >= 1; --i) {
        for (int j = 3; j >= 1; --j) {
            int x = n % 10;
            s.board[i][j] = x;
            if (!x) {
                s.x0 = i, s.y0 = j;
            }
            n /= 10;
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    initial_s = transfer(n);
    BFS();
    return 0;
}
