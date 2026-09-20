// Luogu P1208 - [USACO1.3] 混合牛奶 Mixing Milk
// https://www.luogu.com.cn/problem/P1208

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e6 + 10, maxm = 5005;

int n, m, cost, milk;
pair<int, int> a[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i) {
        if (milk + a[i].second <= n) {
            milk += a[i].second;
            cost += a[i].first * a[i].second;
        } else {
            cost += (n - milk) * a[i].first;
            break;
        }
    }
    cout << cost;
    return 0;
}