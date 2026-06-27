// Problem:  AtCoder Beginner Contest 464 A - Decisive Battle
// Link:     https://atcoder.jp/contests/abc464/tasks/abc464_a
// Author:   nine19een
// Date:     2026-06-27

#include <bits/stdc++.h>
using namespace std;

string s;
int e, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (char c: s) {
        if (c == 'E') {
            e++;
        } else {
            w++;
        }
    }
    cout << (e > w ? "East" : "West");
    return 0;
}
