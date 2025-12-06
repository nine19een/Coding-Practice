// Problem:  AtCoder Beginner Contest 435 B - No-Divisible Range
// Link:     https://atcoder.jp/contests/abc435/tasks/abc435_b
// Author:   nine19een
// Date:     2025-12-06

#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;

int n, pre[maxn], a[maxn], cnt;

bool check(int l, int r, int x) {
    for (int i = l; i <= r; ++i) {
        if (x % a[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    for (int r = 1; r <= n; ++r) {
        for (int l = 1; l <= r; ++l) {
            cnt += check(l, r, pre[r] - pre[l - 1]);
        }
    }
    cout << cnt;
}
