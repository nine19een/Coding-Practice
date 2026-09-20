// Problem:  Luogu B2123 字符串 p 型编码
// Link:     https://www.luogu.com.cn/problem/B2123
// Author:   nine19een
// Date:     2025-11-15

#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    s += ' ';
    char current_num = s.front();
    int cnt = 0;
    for (char c : s) {
        if (c == current_num) {
            cnt++;
        }
        else {
            cout << cnt << current_num;
            current_num = c;
            cnt = 1;
        }
    }
    return 0;
}