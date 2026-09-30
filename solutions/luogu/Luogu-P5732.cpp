// Luogu P5732 【深基5.习7】杨辉三角
// https://www.luogu.com.cn/problem/P5732

#include <bits/stdc++.h>
using namespace std;

int a[25], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (j == 1 || j == i) {
                a[j] = 1;
            } else {
                a[j] += a[j - 1];
            }
            cout << a[j] << " ";
        }
        cout << '\n';
    }
    return 0;
}