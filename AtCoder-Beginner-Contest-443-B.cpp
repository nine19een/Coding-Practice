// Problem:  AtCoder Beginner Contest 443 B - Setsubun
// Link:     https://atcoder.jp/contests/abc438/tasks/abc443_b
// Author:   nine19een
// Date:     2026-01-31

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int sum = n, cnt = 0;
    while (sum < k) {
        cnt++;
        sum += n + cnt;
    }
    cout << cnt;
    return 0;
}
