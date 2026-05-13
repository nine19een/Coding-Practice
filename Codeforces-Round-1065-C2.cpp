// Problem:  Codeforces Round 1065 C2. Renako Amaori and XOR Game (hard version)
// Link:     https://codeforces.com/contest/2171/problem/C2
// Author:   nine19een
// Date:     2025-11-21

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
    int n, xor_sum = 0, msb;
    cin >> n;
    vector<int> a(n + 5), b(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        xor_sum ^= a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        xor_sum ^= b[i];
    }
    if (!xor_sum) {
        cout << "Tie" << '\n';
        return;
    }
    for (int i = 20; i >= 0; --i) {
        if (1 & (xor_sum >> i)) {
            msb = i;
            break;
        }
    }
    for (int i = n; i > 0; --i) {
        if (((a[i] ^ b[i]) >> msb) & 1) {
            cout << ((i & 1) ? "Ajisai" : "Mai") << '\n';
            return;
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
