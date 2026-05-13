// Problem:  Codeforces Round 1068 B. Niko's Tactical Cards
// Link:     https://codeforces.com/contest/2173/problem/B
// Author:   nine19een
// Date:     2025-12-05

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
    int n;
    cin >> n;
    vector<ll> a(n + 5), b(n + 5), dp_max(n + 5), dp_min(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    dp_max[0] = 0;
    dp_min[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp_max[i] = max(dp_max[i - 1] - a[i], b[i] - dp_min[i - 1]);
        dp_min[i] = min(dp_min[i - 1] - a[i], b[i] - dp_max[i - 1]);
    }
    cout << dp_max[n] << '\n';
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
