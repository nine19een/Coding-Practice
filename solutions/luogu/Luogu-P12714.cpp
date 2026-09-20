// Problem:  Luogu P12714 [Algo Beat Contest 002 A] A to Z
// Link:     https://www.luogu.com.cn/problem/P12714
// Author:   nine19een
// Date:     2025-11-23

#include<bits/stdc++.h>
using namespace std;

int cnt;

void op() {
    string s;
    vector<int> lectter(30, 0);
    cin >> s;
    for (char c: s) {
        lectter[c - 'a']++;
        if (lectter[c - 'a'] > 1) {
            return;
        }
    }
    cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        op();
    }
    cout << cnt;
    return 0;
}
