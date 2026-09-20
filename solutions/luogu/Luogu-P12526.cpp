// Problem:  Luogu P12526 [XJTUPC 2025] 纸牌大师
// Link:     https://www.luogu.com.cn/problem/P12526
// Author:   nine19een
// Date:     2025-12-01

#include<bits/stdc++.h>
using namespace std;

int a1, a2, a3;

int main() {
    cin >> a1 >> a2 >> a3;
    if (a1 == a2 && a2 == a3) {
        cout << 100 + a1 + a2 + a3;
    } else {
        cout << a1 + a2 + a3;
    }
    return 0;
}
