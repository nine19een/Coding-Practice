// Problem:  Luogu B2117 整理药名
// Link:     https://www.luogu.com.cn/problem/B2117
// Author:   nine19een
// Date:     2025-11-10

#include<bits/stdc++.h>
using namespace std;

int n;

void tidy() {
    string s;
    cin >> s;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it == s.begin()) {
            if (*it >= 'a' && *it <= 'z') {
                *it = toupper(*it);
            }
            continue;
        }
        *it = tolower(*it);
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        tidy();
    }
    return 0;
}