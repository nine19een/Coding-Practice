// Problem:  Luogu B2122 单词翻转
// Link:     https://www.luogu.com.cn/problem/B2122
// Author:   nine19een
// Date:     2025-11-14

#include<bits/stdc++.h>
using namespace std;

string s, word;

int main() {
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);
    getline(cin, s);
    s += ' ';
    // cout << s << endl;
    for (char c: s) {
        if (c != ' ') {
            word += c;
        } else if (c == ' ') {
            reverse(word.begin(), word.end());
            cout << word << endl;
            word.clear();
        }
    }
    return 0;
}
