// Problem:  AtCoder Beginner Contest 460 C - Sushi
// Link:     https://atcoder.jp/contests/abc460/tasks/abc460_c
// Author:   nine19een
// Date:     2026-05-30

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
priority_queue<int, vector<int>, greater<> > a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b.push(x);
    }
    while (!a.empty() && !b.empty()) {
        int cur_a = a.top();
        a.pop();
        int cur_b = b.top();
        b.pop();
        if (2 * cur_a >= cur_b) {
            cnt++;
        } else {
            b.push(cur_b);
        }
    }
    cout << cnt;
    return 0;
}
