// Problem:  Luogu B2043 判断能否被 3，5，7 整除
// Link:     https://www.luogu.com.cn/problem/B2043
// Author:   nine19een
// Date:     2025-10-20

#include <bits/stdc++.h>
using namespace std;

int x;
bool none = true;

int main() {
    cin >> x;
    if (x % 3 == 0) {
        none = false;
        cout << 3 << " ";
    }
    if (x % 5 == 0) {
        none = false;
        cout << 5 << " ";
    }
    if (x % 7 == 0) {
        none = false;
        cout << 7 << " ";
    }
    if (none) {
        cout << "n";
    }
    return 0;
}