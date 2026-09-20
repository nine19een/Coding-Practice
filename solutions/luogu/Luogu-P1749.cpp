// Problem:  Luogu P1749 [入门赛 #19] 分饼干 II
// Link:     https://www.luogu.com.cn/problem/P1749
// Author:   nine19een
// Date:     2025-12-12

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool yes(ll n, ll k) {
    return n >= (k + 1) / 2 * k;
}

void op() {
    ll n, k;
    cin >> n >> k;
    cout << (yes(n, k) ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
