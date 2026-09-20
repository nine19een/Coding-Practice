// Problem:  Luogu B2115 密码翻译
// Link:     https://www.luogu.com.cn/problem/B2115
// Author:   nine19een
// Date:     2025-11-07

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e4 + 5;

char s[maxn];

void deciphering(int len) {
    for (int i = 0; i < len; i++) {
        if ((s[i] > 'a' && s[i] <= 'z') || (s[i] > 'A' && s[i] <= 'Z')) {
            s[i] -= 1;
        }
        else if (s[i] == 'a' || s[i] == 'A') {
            s[i] += 25;
        }
    }
}

int main() {
    cin.getline(s, maxn);
    int len = strlen(s);
    deciphering(len);
    cout << s;
    return 0;
}