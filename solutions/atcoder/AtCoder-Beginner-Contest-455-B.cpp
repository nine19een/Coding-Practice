// Problem:  AtCoder Beginner Contest 455 B - Spiral Galaxy
// Link:     https://atcoder.jp/contests/abc455/tasks/abc455_b
// Author:   nine19een
// Date:     2026-04-25

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 15;

int H, W;
ll cnt;
char grid[maxn][maxn];

bool check(int h1, int h2, int w1, int w2) {
    for (int i = h1; i <= h2; ++i) {
        for (int j = w1; j <= w2; ++j) {
            if (grid[i][j] != grid[h1 + h2 - i][w1 + w2 - j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int h1 = 1; h1 <= H; ++h1) {
        for (int h2 = h1; h2 <= H; ++h2) {
            for (int w1 = 1; w1 <= W; ++w1) {
                for (int w2 = w1; w2 <= W; ++w2) {
                    if (check(h1, h2, w1, w2)) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
