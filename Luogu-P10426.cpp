// Problem:  Luogu P10426 [蓝桥杯 2024 省 B] 宝石组合
// Link:     https://www.luogu.com.cn/problem/P10426
// Author:   nine19een
// Date:     2026-04-07

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, a[maxn], appear[maxn], max_a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        appear[a[i]]++;
        max_a = max(a[i], max_a);
    }
    int gcd = max_a;
    for (; gcd >= 1; --gcd) {
        int cnt = 0, ans[5];
        for (int d = gcd; d <= max_a; d += gcd) {
            if (appear[d]) {
                int t = appear[d];
                while (t--) {
                    ans[++cnt] = d;
                    if (cnt == 3) {
                        for (int i = 1; i <= 3; ++i) {
                            cout << ans[i] << " ";
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}