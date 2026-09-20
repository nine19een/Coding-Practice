// Problem:  AtCoder Beginner Contest 436 B - Magic Square
// Link:     https://atcoder.jp/contests/abc436/tasks/abc436_b
// Author:   nine19een
// Date:     2025-12-13

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;

int n, a[maxn][maxn];

int main() {
    cin >> n;
    int x = 1, y = n / 2 + 1;
    int N = n * n;
    a[x][y] = 1;
    for (int i = 2; i <= n * n; ++i) {
        int new_x = (x - 1 >= 1) ? x - 1 : n;
        int new_y = (y + 1 <= n) ? y + 1 : 1;
        if (a[new_x][new_y]) {
            x++;
            a[x][y] = i;
        } else {
            a[x = new_x][y = new_y] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
