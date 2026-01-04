// Problem:  AtCoder Beginner Contest 439 B - Happy Number
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_b
// Author:   nine19een
// Date:     2026-01-04

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2030;

int n, cnt[maxn];

bool isHappy(int n) {
    int sum = 0;
    while (1) {
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        cnt[sum]++;
        if (sum == 1) {
            return true;
        }
        if (cnt[sum] == 2) {
            return false;
        }
        n = sum;
        sum = 0;
    }
}

int main() {
    cin >> n;
    cout << (isHappy(n) ? "Yes" : "No");
    return 0;
}
