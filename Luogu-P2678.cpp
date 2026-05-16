// Problem:  Luogu P2678 [NOIP 2015 提高组] 跳石头
// Link:     https://www.luogu.com.cn/problem/P2678
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;

int L, n, m, rock[maxn];

bool Available(int x) {
    int cnt = 0, last_dis = 0;
    bool move = false;
    for (int i = 1; i <= n + 1; i++) {
        int dis = rock[i] - rock[i - 1];
        if (dis + last_dis < x) {
            last_dis += dis;
            cnt++;
        } else {
            last_dis = 0;
        }
    }
    if (cnt <= m) {
        return true;
    }
    return false;
}

int Binary() {
    int l = 1, r = L + 1;
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
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> rock[i];
    }
    rock[n + 1] = L;
    cout << Binary() << '\n';
    return 0;
}