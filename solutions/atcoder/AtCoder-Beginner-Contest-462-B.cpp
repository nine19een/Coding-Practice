// Problem:  AtCoder Beginner Contest 462 B - Gift
// Link:     https://atcoder.jp/contests/abc462/tasks/abc462_b
// Author:   nine19een
// Date:     2026-06-13

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;

int n;
set<int> b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a;
            cin >> a;
            b[a].insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i].size() << " ";
        for (int p: b[i]) {
            cout << p << " ";
        }
        cout << '\n';
    }
    return 0;
}
