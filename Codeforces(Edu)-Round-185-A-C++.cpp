// Problem:  Educational Codeforces Round 185 A. Maximum Neighborhood
// Link:     https://codeforces.com/contest/2170/problem/A
// Author:   nine19een
// Date:     2025-11-28

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;

int t, a[maxn][maxn], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool available(int x, int y, int n) {
    return x <= n && x >= 1 && y <= n && y >= 1;
}

int Sum(int x, int y, int n) {
    int sum = a[x][y];
    for (int i = 0; i <= 3; ++i) {
        int new_x = x + dx[i], new_y = y + dy[i];
        if (available(new_x, new_y, n)) {
            sum += a[new_x][new_y];
        }
    }
    return sum;
}

void op() {
    int n, cnt = 1, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = cnt++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(Sum(i, j, n), ans);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
