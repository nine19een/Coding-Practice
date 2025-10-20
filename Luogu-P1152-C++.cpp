// Problem:  Luogu P1152 欢乐的跳
// Link:     https://www.luogu.com.cn/problem/P1152
// Author:   nine19een
// Date:     2025-10-20

#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e3 + 5;

int n, a[maxn];
bool cnt[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i >= 2) {
            if (abs(a[i] - a[i - 1]) < n) {
                cnt[abs(a[i] - a[i - 1])] = true;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!cnt[i]) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}
