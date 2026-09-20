// Problem:  AtCoder Beginner Contest 459 B - 459
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_b
// Author:   nine19een
// Date:     2026-05-23

#include<bits/stdc++.h>
using namespace std;

int n;

int Num(char c) {
    if (c == 'a' || c == 'b' || c == 'c') {
        return 2;
    }
    if (c == 'd' || c == 'e' || c == 'f') {
        return 3;
    }
    if (c == 'g' || c == 'h' || c == 'i') {
        return 4;
    }
    if (c == 'j' || c == 'k' || c == 'l') {
        return 5;
    }
    if (c == 'm' || c == 'n' || c == 'o') {
        return 6;
    }
    if (c == 'p' || c == 'q' || c == 'r' || c == 's') {
        return 7;
    }
    if (c == 't' || c == 'u' || c == 'v') {
        return 8;
    }
    if (c == 'w' || c == 'x' || c == 'y' || c == 'z') {
        return 9;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        cout << Num(s.front());
    }
}
