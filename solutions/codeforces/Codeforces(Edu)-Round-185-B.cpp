// Problem:  Educational Codeforces Round 185 B. Addition on a Segment
// Link:     https://codeforces.com/contest/2170/problem/B
// Author:   nine19een
// Date:     2025-11-28

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

int t;

void op() {
    ll n, tot = 0, cnt_not0 = 0, margin;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        tot += num;
        cnt_not0 += num ? 1 : 0;
    }
    margin = tot - n;
    if (!margin) {
        cout << 1 << '\n';
        return;
    }
    if (cnt_not0 <= margin) {
        cout << cnt_not0 << '\n';
    } else {
        cout << margin + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
