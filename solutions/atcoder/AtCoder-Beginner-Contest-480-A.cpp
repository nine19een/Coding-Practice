// AtCoder Beginner Contest 480 A - ADjacent
// https://atcoder.jp/contests/abc480/tasks/abc480_a

#include <bits/stdc++.h>
using namespace std;

pair<int, int> A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            char c;
            cin >> c;
            if (c == 'A') {
                A = {i, j};
            } else if (c == 'B') {
                B = {i, j};
            } else if (c == 'C') {
                C = {i, j};
            } else {
                D = {i, j};
            }
        }
    }
    if (A.first == D.first || A.second == D.second) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
