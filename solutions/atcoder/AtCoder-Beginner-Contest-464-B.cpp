// Problem:  AtCoder Beginner Contest 464 B - Crop
// Link:     https://atcoder.jp/contests/abc464/tasks/abc464_b
// Author:   nine19een
// Date:     2026-06-27

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 55;

int H, W, l = maxn, r, up = maxn, down;
char pic[maxn][maxn];

void ck(int x, int y) {
    l = min(l, y);
    r = max(r, y);
    up = min(up, x);
    down = max(down, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> pic[i][j];
            if (pic[i][j] == '#') {
                ck(i, j);
            }
        }
    }
    for (int i = up; i <= down; i++) {
        for (int j = l; j <= r; j++) {
            cout << pic[i][j];
        }
        cout << '\n';
    }
    return 0;
}
