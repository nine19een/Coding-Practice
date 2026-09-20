// Problem:  Luogu P3383 【模板】线性筛素数
// Link:     https://www.luogu.com.cn/problem/P3383
// Author:   nine19een
// Date:     2025-12-04

#include<bits/stdc++.h>
using namespace std;
const int MAXP = 6e6, MAXN = 1e8 + 5;

int n, q;
vector<int> primes;
bool not_prime[MAXN];

void findPrimes() {
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (int p: primes) {
            if (i > n / p) {
                break;
            }
            not_prime[p * i] = true;
            if (i % p == 0) {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    primes.reserve(MAXP);
    findPrimes();
    for (int i = 1; i <= q; ++i) {
        int idx;
        cin >> idx;
        cout << primes[idx - 1] << '\n';
    }
    return 0;
}