// Problem:  Luogu P9240 [蓝桥杯 2023 省 B] 冶炼金属
// Link:     https://www.luogu.com.cn/problem/P9240
// Author:   nine19een
// Date:     2026-04-08

#include<bits/stdc++.h>
using namespace std;

int n, L = 0, R = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        int l = a / (b + 1) + 1;
        int r = a / b;
        L = max(L, l);
        R = min(R, r);
    }
    cout << L << " " << R;
    return 0;
}
