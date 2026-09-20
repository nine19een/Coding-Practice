// Problem:  Luogu P1320 压缩技术（续集版）
// Link:     https://www.luogu.com.cn/problem/P1320
// Author:   nine19een
// Date:     2025-12-02

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s_1st;
    getline(cin, s_1st);
    int n = s_1st.length();
    for (int i = 1; i < n; ++i) {
        string s;
        getline(cin, s);
        s_1st += s;
    }
    cout << n << " ";
    int cnt[2] = {0, 0};
    bool recent_num = false;
    for (char c: s_1st) {
        if (c - '0' == recent_num) {
            cnt[recent_num]++;
        } else {
            cout << cnt[recent_num] << " ";
            cnt[recent_num] = 0;
            recent_num ^= 1;
            cnt[recent_num]++;
        }
    }
    cout << cnt[recent_num];
    return 0;
}
