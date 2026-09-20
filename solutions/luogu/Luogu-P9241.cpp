// Problem:  Luogu P9241 [蓝桥杯 2023 省 B] 飞机降落
// Link:     https://www.luogu.com.cn/problem/P9241
// Author:   nine19een
// Date:     2026-04-08

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 15;

int t[maxn], d[maxn], l[maxn], cnt, n;
bool vis[maxn], y;

void DFS(int num, int nowt) {
    if (cnt == n) {
        y = true;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        int nxtt = nowt + l[num];
        if (vis[i] || nxtt > t[i] + d[i]) {
            continue;
        }
        if (t[i] > nxtt) {
            nxtt = t[i];
        }
        vis[i] = true;
        cnt++;
        DFS(i, nxtt);
        if (y) {
            return;
        }
        vis[i] = false;
        cnt--;
    }
}

void init() {
    memset(vis, 0, sizeof vis);
    cnt = 0;
    y = false;
}

void op() {
    init();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> d[i] >> l[i];
    }
    for (int i = 1; i <= n; ++i) {
        cnt++;
        vis[i] = true;
        DFS(i, t[i]);
        if (y) {
            cout << "YES" << '\n';
            return;
        }
        cnt--;
        vis[i] = false;
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        op();
    }
    return 0;
}
