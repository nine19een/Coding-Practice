// Problem:  Luogu B2120 单词的长度
// Link:     https://www.luogu.com.cn/problem/B2120
// Author:   nine19een
// Date:     2025-11-13

#include<bits/stdc++.h>
using namespace std;

string s;
bool flag = false;

int main() {
    getline(cin,s);
    s += ' ';
    int cnt = 0;
    for (char c : s) {
        if (c != ' ') {
            cnt++;
        } else {
            if (!cnt) {
                continue;
            }
            if (!flag) {
                cout << cnt;
            }else {
                cout << "," << cnt;
            }
            flag = true;
            cnt = 0;
        }
    }
    return 0;
}