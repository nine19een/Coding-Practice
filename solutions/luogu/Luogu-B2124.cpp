// Problem:  Luogu B2124 判断字符串是否为回文
// Link:     https://www.luogu.com.cn/problem/B2124
// Author:   nine19een
// Date:     2025-11-16

#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    string s_copy = s;
    reverse(s_copy.begin(), s_copy.end());
    if (s_copy == s) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
