// Problem:  Luogu P1610 鸿山洞的灯
// Link:     https://www.luogu.com.cn/problem/P1610
// Author:   nine19een
// Date:     2026-01-29

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, d, p[maxn];

int CNT() {
    int last_pos = 1, cnt = 0;
    for (int i = 2; i < n; i++) {
        if (p[i + 1] - p[last_pos] <= d) {
            cnt++;
        } else {
            last_pos = i;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    cout << CNT();
    return 0;
}
