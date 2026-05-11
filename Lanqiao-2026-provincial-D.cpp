// Problem:  蓝桥杯 2026 省 B D题 - 蓝桥竞技
// Link:     https://www.luogu.com.cn/problem/P16235
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
    int n, max_a = 0;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        sum += ai;
        max_a = max(max_a, ai);
    }
    if (sum % 5 == 0 && max_a <= sum / 5) {
        cout << "T\n";
    } else {
        cout << "F\n";
    }
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
