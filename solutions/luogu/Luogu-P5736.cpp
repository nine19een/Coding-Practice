// Problem:  P5736 【深基7.例2】质数筛
// Link:     https://www.luogu.com.cn/problem/P5736
// Author:   nine19een
// Date:     2026-05-23

#include <bits/stdc++.h>
using namespace std;
constexpr int maxa = 1e5 + 5;

int n, max_a, a[maxa];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ans.reserve(maxa);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    vector<bool> isPrime(max_a + 5, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= max_a; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max_a; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (isPrime[a[i]]) {
            cout << a[i] << " ";
        }
    }
    return 0;
}