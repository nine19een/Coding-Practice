// Problem:  Luogu P1824 [USACO05FEB] 进击的奶牛 Aggressive Cows G
// Link:     https://www.luogu.com.cn/problem/P1824
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m, pos[maxn];

bool Available(int x) {
    int cnt = 1, last_dis = 0;
    for (int i = 2; i <= n; i++) {
        int dis = pos[i] - pos[i - 1];
        if (dis + last_dis >= x) {
            cnt++;
            last_dis = 0;
        } else {
            last_dis += dis;
        }
    }
    if (cnt >= m) {
        return true;
    }
    return false;
}

int Binary() {
    int l = 1, r = pos[n];
    while (l < r) {
        int mid = (l + r) / 2;
        if (Available(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + n + 1);
    cout << Binary();
    return 0;
}