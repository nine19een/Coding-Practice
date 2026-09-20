// Problem:  Luogu P12133 [蓝桥杯 2025 省 B] 产值调整
// Link:     https://www.luogu.com.cn/problem/P12133
// Author:   nine19een
// Date:     2026-04-05

#include<bits/stdc++.h>
using namespace std;

int val(int x, int y) {
    return (x + y) / 2;
}

void op() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    k = k >= 40 ? 40 : k;
    while (k--) {
        int na = a, nb = b, nc = c;
        na = val(b, c);
        nb = val(a, c);
        nc = val(a, b);
        a = na, b = nb, c = nc;
    }
    cout << a << " " << b << " " << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}