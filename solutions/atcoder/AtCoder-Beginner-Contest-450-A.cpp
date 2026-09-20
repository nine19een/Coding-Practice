// Problem:  AtCoder Beginner Contest 450 A - 3,2,1,GO
// Link:     https://atcoder.jp/contests/abc450/tasks/abc450_a
// Author:   nine19een
// Date:     2026-03-21

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        if (i == 1) {
            cout << 1;
            break;
        }
        cout << i << ",";
    }
    return 0;
}
