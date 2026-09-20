// Problem:  Luogu P2440 木材加工
// Link:     https://www.luogu.com.cn/problem/P2440
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, k, wood[maxn], max_len;

int CNT(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += wood[i] / x;
    }
    return cnt;
}

int Binary() {
    int l = 1, r = max_len + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (CNT(mid) < k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> wood[i];
        max_len = max(max_len, wood[i]);
    }
    cout << Binary();
    return 0;
}
