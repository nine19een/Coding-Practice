// Problem:  Luogu B4061 位运算 2
// Link:     https://www.luogu.com.cn/problem/B4061
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 1 << 25;

ll a, b;

int main() {
    cin >> a >> b;
    cout << a * (1 << b) << endl << a / (1 << b) << endl << ((a >> b) & 1) << endl << (a & ~(1 << b)) << endl << (a | (1 << b)) << endl << (a ^ (1 << b));
    return 0;
}
