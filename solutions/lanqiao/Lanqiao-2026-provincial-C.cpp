// Problem:  蓝桥杯 2026 省 B C题 - 循环右移
// Link:     https://www.luogu.com.cn/problem/P16234
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
    ll n, x, y;
    cin >> n >> x >> y;
    cout << max(0ll, y - x + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
