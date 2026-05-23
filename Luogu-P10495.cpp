// Problem:  P10495 阶乘分解
// Link:     https://www.luogu.com.cn/problem/P10495
// Author:   nine19een
// Date:     2026-05-23

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 5;

int n;
vector<bool> isPrime(maxn, true);
vector<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n / i; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    for (int p: primes) {
        int cnt = 0;
        int t = n;
        while (t) {
            cnt += t / p;
            t /= p;
        }
        cout << p << " " << cnt << '\n';
    }
    return 0;
}
