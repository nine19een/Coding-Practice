// Problem:  Codeforces Global Round 31 A. Carnival Wheel
// Link:     https://codeforces.com/contest/2180/problem/A
// Author:   nine19een
// Date:     2025-12-19

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
    int l, a, b, max_ans = 0;
    cin >> l >> a >> b;
    int start_idx = a, cnt = 0;
    while (a != start_idx || !cnt) {
        cnt++;
        max_ans = max(a, max_ans);
        a = (a + b) % l;
        max_ans = max(a, max_ans);
    }
    cout << max_ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
