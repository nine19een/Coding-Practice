// Problem:  AtCoder Beginner Contest 459 A - Hell, World!
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_a
// Author:   nine19een
// Date:     2026-05-23

#include<bits/stdc++.h>
using namespace std;

int n;
string s = "1HelloWorld";

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cout << s[i];
    }
    for (int i = n + 1; i <= 10; ++i) {
        cout << s[i];
    }
}
