// Problem:  AtCoder Beginner Contest 435 C - Domino
// Link:     https://atcoder.jp/contests/abc435/tasks/abc435_c
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;

int n, a[maxn], cnt, waiting_down;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        waiting_down = max(waiting_down, a[i]);
        cnt++;
        waiting_down--;
        if (waiting_down) {
            continue;
        }
        break;
    }
    cout << cnt;
}
