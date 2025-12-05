// Problem:  Codeforces Round 1068 A. Sleeping Through Classes
// Link:     https://codeforces.com/contest/2173/problem/A
// Author:   nine19een
// Date:     2025-12-05

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
    int n, k, cnt = 0, cant_sleep = 0;
    string s;
    cin >> n >> k >> s;
    for (char c: s) {
        if (c == '1') {
            cant_sleep = k;
        } else if (c == '0') {
            if (!cant_sleep) {
                cnt++;
            }
            cant_sleep -= cant_sleep ? 1 : 0;
        }
    }
    cout << cnt << '\n';
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
