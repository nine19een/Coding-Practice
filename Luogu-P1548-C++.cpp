// Problem:  Luogu P1548 [NOIP 1997 普及组] 棋盘问题
// Link:     https://www.luogu.com.cn/problem/P1548
// Author:   nine19een
// Date:     2025-10-18
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, cnt_square, cnt_rectangle;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ll x = (n - i + 1) * (m - j + 1);
            if (i == j) {
                cnt_square += x;
            }
            else {
                cnt_rectangle += x;
            }
        }
    }
    cout << cnt_square << " " << cnt_rectangle;
    return 0;
}