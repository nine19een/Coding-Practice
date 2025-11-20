// Problem:  Codeforces Round 1065 C1. Renako Amaori and XOR Game (easy version)
// Link:     https://codeforces.com/contest/2171/problem/C1
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;

int t, a[maxn], b[maxn];

void op() {
    int n, cnt_odd = 0, cnt_even = 0, cnt_1 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt_1 += a[i] ? 1 : 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        cnt_1 += b[i] ? 1 : 0;
        if (!(cnt_1 & 1)) {
            cout << "Tie" << '\n';
            return;
        }
        bool last_person; //1->odd 0->even
        for (int i = n; i >= 1; --i) {
            if (a[i] != b[i]) {
                last_person = (i & 1);
                break;
            }
        }
        if (last_person) {
            cout << "Ajisai" << '\n';
        } else {
            cout << "Mai" << '\n';
        }
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
