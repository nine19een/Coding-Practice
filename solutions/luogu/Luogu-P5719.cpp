// Luogu P5716 【深基3.例9】月份天数
// https://www.luogu.com.cn/problem/P5716

#include <bits/stdc++.h>
using namespace std;

int y, m, month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> y >> m;
    cout << (leap(y) && m == 2 ? 29 : month[m]);
    return 0;
}