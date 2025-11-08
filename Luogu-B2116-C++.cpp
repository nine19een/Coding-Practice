// Problem:  Luogu B2116 加密的病历单
// Link:     https://www.luogu.com.cn/problem/B2116
// Author:   nine19een
// Date:     2025-11-08

#include<bits/stdc++.h>
using namespace std;

string s;

void deciphering() {
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = toupper(c);
        }
        else if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
    }
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if ((c >= 'a' && c <= 'w') || (c >= 'A' && c <= 'W')) {
            c += 3;
        }
        else {
            c -= 23;
        }
    }
}

int main() {
    cin >> s;
    deciphering();
    cout << s;
    return 0;
}