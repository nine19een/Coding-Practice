// Problem:  AtCoder Beginner Contest 458 B - Count Adjacent Cells
// Link:     https://atcoder.jp/contests/abc458/tasks/abc458_b
// Author:   nine19een
// Date:     2026-05-16

#include <bits/stdc++.h>
using namespace std;

int h, w, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool inRange(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
}

int edgeAdjacent(int x, int y) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inRange(nx, ny)) {
            res++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << edgeAdjacent(i, j) << " ";
        }
        cout << '\n';
    }
    return 0;
}
