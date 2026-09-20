// Problem:  AtCoder Beginner Contest 467 D - Concentric Circles
// Link:     https://atcoder.jp/contests/abc467/tasks/abc467_d
// Author:   nine19een
// Date:     2026-07-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        ll dx1 = qx - px, dy1 = qy - py, dx2 = sx - rx, dy2 = sy - ry;
        ll cross = dx1 * dy2 - dx2 * dy1;
        if (cross) {
            cout << "Yes\n";
            continue;
        }
        ll mx = rx + sx - px - qx, my = ry + sy - py - qy;
        ll dot = mx * dx1 + my * dy1;
        cout << (!dot ? "Yes\n" : "No\n");
    }
    return 0;
}
