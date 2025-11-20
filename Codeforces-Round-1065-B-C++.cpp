// Problem:  Codeforces Round 1065 B. Yuu Koito and Minimum Absolute Sum
// Link:     https://codeforces.com/contest/2171/problem/B
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;

int t, a[maxn];

void op() {
    int n, left, right;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != -1) {
            left = a[i];
            break;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] != -1) {
            right = a[i];
            break;
        }
    }
    if (a[1] == -1 && a[n] != -1) {
        a[1] = right;
    }
    if (a[1] != -1 && a[n] == -1) {
        a[n] = left;
    }
    cout << abs(a[n] - a[1]) << '\n';
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << " ";
    }
    memset(a, sizeof(a), 0);
    cout << '\n';
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
