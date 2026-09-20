// Problem:  Luogu P1424 小鱼的航程（改进版）
// Link:     https://www.luogu.com.cn/problem/P1424
// Author:   nine19een
// Date:     2025-11-26

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, n, cnt;

int main() {
    cin >> x >> n;
    while(n--) {
        cnt += x == 6 || x == 7 ? 0 : 1;
        x = x == 7 ? 1 : x + 1;
    }
    cout << cnt * 250 << endl;
    return 0;
}