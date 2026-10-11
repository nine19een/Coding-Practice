// Luogu P1007 独木桥
// https://www.luogu.com.cn/problem/P1007

#include <bits/stdc++.h>
using namespace std;

int l, n, min_t, max_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> n;
    for (int i = 1; i <= n; ++i) {
        int idx;
        cin >> idx;
        min_t = max(min(idx, l - idx + 1), min_t);
        max_t = max(max(idx, l - idx + 1), max_t);
    }
    cout << min_t << " " << max_t;
    return 0;
}
