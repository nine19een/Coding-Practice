// Luogu P2010 [NOIP 2016 普及组] 回文日期
// https://www.luogu.com.cn/problem/P2010

#include <bits/stdc++.h>
using namespace std;

int cnt, date1, date2, days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s1, s2;

int Date(int m, int d) {
    return d % 10 * 10000000 + d / 10 * 1000000 + m % 10 * 100000 + m / 10 * 10000 + m * 100 + d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    date1 = stoi(s1);
    date2 = stoi(s2);
    for (int m = 1; m <= 12; ++m) {
        for (int d = 1; d <= days[m]; ++d) {
            int date = Date(m, d);
            cnt += (date1 <= date && date <= date2 ? 1 : 0);
        }
    }
    cout << cnt;
    return 0;
}
