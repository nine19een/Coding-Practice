// Problem:  Luogu P12132 [蓝桥杯 2025 省 B] 可分解的正整数
// Link:     https://www.luogu.com.cn/problem/P12132
// Author:   nine19een
// Date:     2026-04-05

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, cnt, a[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (num != 1) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
