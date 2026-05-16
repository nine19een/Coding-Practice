// Problem:  AtCoder Beginner Contest 458 D - Chalkboard Median
// Link:     https://atcoder.jp/contests/abc458/tasks/abc458_d
// Author:   nine19een
// Date:     2026-05-16

#include <bits/stdc++.h>
using namespace std;

int x, q;

priority_queue<int> small;
priority_queue<int, vector<int>, greater<> > large;

void op() {
    int a, b;
    cin >> a >> b;
    int cur_biggest = small.top();
    if (a <= cur_biggest) {
        small.push(a);
    } else {
        large.push(a);
    }
    if (b <= cur_biggest) {
        small.push(b);
    } else {
        large.push(b);
    }
    while (small.size() > large.size() + 1) {
        int t = small.top();
        small.pop();
        large.push(t);
    }
    while (large.size() > small.size()) {
        int t = large.top();
        large.pop();
        small.push(t);
    }
    cout << small.top() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> q;
    small.push(x);
    while (q--) {
        op();
    }
    return 0;
}
