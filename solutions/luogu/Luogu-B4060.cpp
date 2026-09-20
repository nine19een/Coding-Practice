// Problem:  Luogu B4060 位运算 1
// Link:     https://www.luogu.com.cn/problem/B4060
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;

int a, b, k;

int main() {
    cin >> a >> b >> k;
    cout << (a & b) << endl << (a | b) << endl << (a ^ b) << endl << (~a) << endl << (a << k) << endl << (a >> k);
    return 0;
}