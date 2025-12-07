// Problem:  Luogu B2144 阿克曼（Ackermann）函数
// Link:     https://www.luogu.com.cn/problem/2144
// Author:   nine19een
// Date:     2025-12-07

#include<bits/stdc++.h>
using namespace std;

int m, n;

int A(int m, int n) {
    if (!m) {
        return n + 1;
    } else if (m > 0 && !n) {
        return A(m - 1, 1);
    } else if (m && n) {
        return A(m - 1, A(m, n - 1));
    }
}

int main() {
    cin >> m >> n;
    cout << A(m, n);
    return 0;
}
