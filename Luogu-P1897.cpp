// Problem:  Luogu P1897 电梯里的尴尬
// Link:     https://www.luogu.com.cn/problem/P1897
// Author:   nine19een
// Date:     2025-11-24

#include<bits/stdc++.h>
using namespace std;

set<int> s;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        s.insert(num);
    }
    cout << s.size() * 5 + *prev(s.end()) * 10 + n;
    return 0;
}
