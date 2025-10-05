// Problem:  Luogu P1012 [NOIP 1998 提高组] 拼数
// Link:     https://www.luogu.com.cn/problem/P1012
// Author:   nine19een
// Date:     2025-10-05
// Method:   自定义sort比较规则

#include<bits/stdc++.h>
using namespace std;

int n;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<string> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << num[i];
    }
    return 0;
}
