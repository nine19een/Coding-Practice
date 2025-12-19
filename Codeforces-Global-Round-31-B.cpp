// Problem:  Codeforces Global Round 31 B. Ashmal
// Link:     https://codeforces.com/contest/2180/problem/B
// Author:   nine19een
// Date:     2025-12-19

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
    int n;
    string s, a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        s = min(s + a, a + s);
    }
    cout << s << '\n';
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
