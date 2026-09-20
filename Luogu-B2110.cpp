// Luogu B2110 - 找第一个只出现一次的字符
// https://www.luogu.com.cn/problem/B2110

#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (char c : s) {
        if (cnt[c - 'a'] == 1) {
            cout << c;
            return 0;
        }
    }
    cout << "no";
    return 0;
}