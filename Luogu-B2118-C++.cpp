// Problem:  Luogu B2118 验证子串
// Link:     https://www.luogu.com.cn/problem/B2118
// Author:   nine19een
// Date:     2025-11-10

#include<bits/stdc++.h>
using namespace std;

string s1, s2;

void match(int len1, int len2, string &s1, string &s2) {
    for (int i = 0; i < len2; i++) {
        if (s2[i] == s1[0]) {
            bool y = true;
            for (int j = 0; j < len1; j++) {
                if (s1[j] != s2[i + j]) {
                    y = false;
                    break;
                }
            }
            if (y) {
                cout << s1 << " is substring of " << s2;
                return;
            }
        }
    }
    cout << "No substring";
}

void check() {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 <= len2) {
        match(len1, len2, s1, s2);
    }
    else {
        match(len2, len1, s2, s1);
    }
}

int main() {
    cin >> s1 >> s2;
    check();
    return 0;
}