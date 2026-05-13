// Problem:  Luogu P1835 素数密度
// Link:     https://www.luogu.com.cn/problem/P1835
// Author:   nine19een
// Date:     2025-12-03

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1000005;

ll l, r, sqrt_r, cnt;
bool not_Prime[MAXN];
vector<ll> primes;

void findPrime() {
    for (ll i = 2; i <= sqrt_r; ++i) {
        if (!not_Prime[i]) {
            primes.push_back(i);
        }
        for (ll p: primes) {
            if (p * i > sqrt_r) {
                break;
            }
            not_Prime[p * i] = true;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void select_p(ll p) {
    ll start = (l + p - 1) / p * p;
    start += start == p ? p : 0;
    for (ll i = start; i <= r; i += p) {
        not_Prime[i - l] = true;
    }
}

void cntLtoR() {
    for (ll i = l; i <= r; ++i) {
        if (i == 1) {
            continue;
        }
        cnt += !not_Prime[i - l];
    }
}

int main() {
    cin >> l >> r;
    sqrt_r = (ll) sqrt(r); //规范写法：sqrt_r = static_cast<ll>(sqrt(r));
    findPrime();
    memset(not_Prime, 0, sizeof(not_Prime));
    for (ll p: primes) {
        select_p(p);
    }
    cntLtoR();
    cout << cnt;
    return 0;
}
