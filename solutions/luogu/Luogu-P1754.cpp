// Problem:  P1754 球迷购票问题
// Link:     https://www.luogu.com.cn/problem/P1754
// Author:   nine19een
// Date:     2026-05-18

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 25;

int n;
ll cat[maxn];

void init() {
    cat[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        cat[i] = cat[i - 1] * (4 * i - 2) / (i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    cout << cat[n];
    return 0;
}
