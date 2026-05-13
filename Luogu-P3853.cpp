// Problem:  Luogu P3853 [TJOI2007] 路标设置
// Link:     https://www.luogu.com.cn/problem/P3853
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int L, n, k, pos[maxn];

bool Available(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int dis = pos[i] - pos[i - 1];
        cnt += (dis - 1) / x;
    }
    if (cnt <= k) {
        return true;
    }
    return false;
}

int Binary() {
    int l = 1, r = L + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (Available(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    cout << Binary();
    return 0;
}
