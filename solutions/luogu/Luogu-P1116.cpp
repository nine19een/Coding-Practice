// Luogu P1116 车厢重组
// https://www.luogu.com.cn/problem/P1116

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;

int n, a[maxn], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] > a[j]) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
