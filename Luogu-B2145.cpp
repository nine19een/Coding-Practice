// Problem:  Luogu B2145 digit 函数
// Link:     https://www.luogu.com.cn/problem/B2145
// Author:   nine19een
// Date:     2025-12-08

#include<bits/stdc++.h>
using namespace std;

int num, k;

int digit(int n, int k) {
    while (--k) {
        n /= 10;
    }
    return n % 10;
}

int main() {
    cin >> num >> k;
    cout << digit(num, k);
    return 0;
}
