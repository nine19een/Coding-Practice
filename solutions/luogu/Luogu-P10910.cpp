// Problem:  Luogu P10910 [蓝桥杯 2024 国 B] 最小字符串
// Link:     https://www.luogu.com.cn/problem/P10910
// Author:   nine19een
// Date:     2025-09-11

#include<bits/stdc++.h>
using namespace std;

int N, M;
string str;
string ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M >> str;
    vector<char> c(M);
    for (char &p: c) {
        cin >> p;
    }
    sort(c.begin(), c.end());
    int i = 0, j = 0;
    while (i != N && j != M) {
        ans += (c[j] < str[i]) ? c[j++] : str[i++];
    }
    if (i < N) {
        ans += str.substr(i);
    }
    if (j < M) {
        ans += string(c.begin() + j, c.end());
    }
    cout << ans;
    return 0;
}