// Problem:  Luogu P1147 连续自然数和
// Link:     https://www.luogu.com.cn/problem/P1147
// Author:   nine19een
// Date:     2025-11-23

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 2e6 + 5;

ll n, a[maxn], prefix[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        prefix[i] = a[i] + prefix[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        ll aim_num = n + prefix[i - 1];
        int r_idx = lower_bound(prefix + i, prefix + n + 1, aim_num) - prefix;
        if (prefix[r_idx] - prefix[i - 1] == n) {
            cout << i << " " << r_idx << '\n';
        }
    }
    return 0;
}
