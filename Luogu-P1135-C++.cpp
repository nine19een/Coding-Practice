// Problem:  Luogu P1135 奇怪的电梯
// Link:     https://www.luogu.com.cn/problem/P1135
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 205;

struct Floor {
    int f, cnt;
};

int n, a, b, k[maxn], d[] = {1, -1};
bool vis[maxn], have_ans;

bool available(int f) {
    return f >= 1 && f <= n && !vis[f];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    queue<Floor> q;
    q.push({a, 0});
    vis[a] = true;
    while (!q.empty()) {
        int cur_f = q.front().f, cur_c = q.front().cnt;
        q.pop();
        if (cur_f == b) {
            cout << cur_c;
            have_ans = true;
            break;
        }
        for (int i = 0; i < 2; ++i) {
            int next_f = cur_f + d[i] * k[cur_f];
            if (available(next_f)) {
                q.push({next_f, cur_c + 1});
                vis[next_f] = true;
            }
        }
    }
    if (!have_ans) {
        cout << -1;
    }
    return 0;
}
