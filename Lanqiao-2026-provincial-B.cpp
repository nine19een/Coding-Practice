// Problem:  蓝桥杯 2026 省 B - B.双碳战略
// Link:     https://www.luogu.com.cn/problem/P16233
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 2026 * qpow(2, 2025) % mod;
    return 0;
}
