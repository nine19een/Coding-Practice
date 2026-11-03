// Campus OJ P124 收集Boris海报
// https://oj.nine19een.com/#library/P124

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2005;

struct Train {
    int t, s, x, y;
};

Train tr[maxn];
int n, dp[maxn], ans;

void init() {
    sort(tr + 1, tr + n + 1, [](const Train &a, const Train &b) {
        return a.t < b.t;
    });
    for (int i = 1; i <= n; ++i) {
        dp[i] = tr[i].s;
    }
}

void DP() {
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (tr[i].t - tr[j].t < abs(tr[i].x - tr[j].x) + abs(tr[i].y - tr[j].y)) {
                continue;
            }
            dp[i] = max(dp[i], dp[j] + tr[i].s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tr[i].t >> tr[i].s >> tr[i].x >> tr[i].y;
    }
    init();
    DP();
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}
