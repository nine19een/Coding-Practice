// Problem:  Luogu P1135 奇怪的电梯
// Link:     https://www.luogu.com.cn/problem/P1135
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 205;

int n, a, b, k[maxn], d[] = {1, -1}, times[maxn];

bool available(int f) {
    return f >= 1 && f <= n && times[f] == -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(times, -1, sizeof times);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    queue<int> q;
    q.push(a);
    times[a] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        if (f == b) {
            break;
        }
        for (int i = 0; i < 2; ++i) {
            int nf = f + d[i] * k[f];
            if (available(nf)) {
                q.push(nf);
                times[nf] = times[f] + 1;
            }
        }
    }
    cout << (times[b] == -1 ? -1 : times[b]);
    return 0;
}
