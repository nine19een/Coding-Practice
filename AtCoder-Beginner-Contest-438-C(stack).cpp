// Problem:  AtCoder Beginner Contest 438 C - 1D puyopuyo
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_c
// Author:   nine19een
// Date:     2025-12-30
// Method:   stack

#include<bits/stdc++.h>
using namespace std;

struct S {
    int num, cnt;
};

int n;
stack<S> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        if (a.empty() || a.top().num != ai) {
            a.push({ai, 1});
            continue;
        }
        if (a.top().num == ai) {
            a.top().cnt++;
            if (a.top().cnt == 4) {
                a.pop();
            }
        }
    }
    int ans = 0;
    while (!a.empty()) {
        ans += a.top().cnt;
        a.pop();
    }
    cout << ans;
    return 0;
}
