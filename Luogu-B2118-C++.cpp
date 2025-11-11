// Problem:  Luogu B2118 验证子串
// Link:     https://www.luogu.com.cn/problem/B2118
// Author:   nine19een
// Date:     2025-11-10

#include<bits/stdc++.h>
using namespace std;

string s1, s2;

void match(string &a, string &b) {
    if (b.find(a) != string::npos) {
        cout << a << " is substring of " << b;
    } else {
        cout << "No substring";
    }
}

void check() {
    if (s1.length() <= s2.length()) {
        match(s1, s2);
    } else {
        match(s2, s1);
    }
}

int main() {
    cin >> s1 >> s2;
    check();
    return 0;
}
