// Problem:  P1595 信封问题
// Link:     https://www.luogu.com.cn/problem/P1595
// Author:   nine19een
// Date:     2026-05-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 25;

int n;
ll D[maxn];

void init() {
    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i < maxn; ++i) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    cout << D[n];
    return 0;
}
