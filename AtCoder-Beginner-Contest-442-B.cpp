// Problem:  AtCoder Beginner Contest 442 B - Music Player
// Link:     https://atcoder.jp/contests/abc438/tasks/abc442_b
// Author:   nine19een
// Date:     2026-01-24

#include<bits/stdc++.h>
using namespace std;

int q, loud;
bool play;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            loud++;
        }
        if (a == 2 && loud >= 1) {
            loud--;
        }
        if (a == 3) {
            play ^= 1;
        }
        if (loud >= 3 && play) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
