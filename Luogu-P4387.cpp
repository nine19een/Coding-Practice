// Problem:  Luogu P4387 【深基15.习9】验证栈序列
// Link:     https://www.luogu.com.cn/problem/P4387
// Author:   nine19een
// Date:     2026-01-19

#include <bits/stdc++.h>
using namespace std;

int q;

void op() {
    int n;
    cin >> n;
    const int N = n + 5;
    vector<int> pushed(N), poped(N);
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> pushed[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> poped[i];
    }
    int j = 1;
    for (int i = 1; i <= n; i++) {
        s.push(pushed[i]);
        while (!s.empty() && s.top() == poped[j]) {
            s.pop();
            j++;
        }
    }
    if (s.empty()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        op();
    }
    return 0;
}
