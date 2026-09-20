// Problem:  AtCoder Beginner Contest 436 A - o-padding
// Link:     https://atcoder.jp/contests/abc436/tasks/abc436_a
// Author:   nine19een
// Date:     2025-12-13

#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int len = s.length();
    for (int i = 1; i <= n - len; ++i) {
        cout << "o";
    }
    cout << s;
    return 0;
}
