// Problem:  Luogu P1009 [NOIP 1998 普及组] 阶乘之和
// Link:     https://www.luogu.com.cn/problem/P1009
// Author:   nine19een
// Date:     2026-05-14

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sum, fac;

vector<int> Mul(vector<int> &a, int b) {
    vector<int> res;
    int carry = 0;
    for (int i = 0; i < a.size() || carry; i++) {
        if (i < a.size()) {
            carry += a[i] * b;
        }
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

vector<int> Add(vector<int> &a, vector<int> &b) {
    vector<int> res;
    int carry = 0;
    for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
        if (i < a.size()) {
            carry += a[i];
        }
        if (i < b.size()) {
            carry += b[i];
        }
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

void Solve() {
    sum.push_back(0);
    fac.push_back(1);
    for (int i = 1; i <= n; i++) {
        fac = Mul(fac, i);
        sum = Add(sum, fac);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    Solve();
    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    return 0;
}
