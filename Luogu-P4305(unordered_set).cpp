// Problem:  P4305 [JLOI2011] 不重复数字
// Link:     https://www.luogu.com.cn/problem/P4305
// Author:   nine19een
// Date:     2025-12-09
// method:   unordered_set

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void Unique() {
    int n;
    unordered_set<ll> s;
    vector<ll> v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (!s.count(x)) {
            s.insert(x);
            v.push_back(x);
        }
    }
    for (ll p: v) {
        cout << p << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        Unique();
    }
    return 0;
}
