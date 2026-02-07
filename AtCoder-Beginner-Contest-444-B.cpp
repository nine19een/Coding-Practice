// Problem:  AtCoder Beginner Contest 444 B - Digit Sum
// Link:     https://atcoder.jp/contests/abc444/tasks/abc444_b
// Author:   nine19een
// Date:     2026-02-07

#include<bits/stdc++.h>
using namespace std;

int n, k, cnt;

void CNT(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    cnt += sum == k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        CNT(i);
    }
    cout << cnt;
    return 0;
}