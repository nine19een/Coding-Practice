// Problem:  蓝桥杯 2026 省 B - G.理想温度
// Link:     https://www.luogu.com.cn/problem/P16238
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, d[maxn], pre0[maxn], a[maxn], b[maxn], ans;
unordered_map<int, vector<int> > um;

int ansOFk(const vector<int> &pos) {
    int base = pre0[n];
    if (pos.size() == 1) {
        return base + 1;
    }
    int cur = 1, best = 1;
    for (auto it = next(pos.begin()); it != pos.end(); ++it) {
        cur = max(1, cur + 1 - pre0[*it - 1] + pre0[*prev(it)]);
        best = max(best, cur);
    }
    return base + best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        d[i] = b[i] - a[i];
        pre0[i] = pre0[i - 1] + (d[i] == 0);
        if (d[i]) {
            um[d[i]].push_back(i);
        }
    }
    ans = pre0[n];
    for (const auto &p: um) {
        ans = max(ans, ansOFk(p.second));
    }
    cout << ans;
    return 0;
}
