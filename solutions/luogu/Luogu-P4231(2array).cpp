// Problem:  Luogu P4231 三步必杀
// Link:     https://www.luogu.com.cn/problem/P4231
// Author:   nine19een
// Date:     2025-11-27
// Method:   初写 用双数组进行二阶差分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 1e7 + 5, maxm = 3e5 + 5;

ll n, m, diff1[maxn], diff2[maxn], XOR, max_val;

void diff(ll l, ll r, ll s, ll e, ll x) {
    diff1[l] += s, diff1[r + 1] -= e;
    diff2[l + 1] -= x, diff2[r + 1] += x;
}

void sum() {
    ll ans_i = 0;
    for (int i = 1; i <= n; i++) {
        diff2[i] += diff2[i - 1];
        ans_i += diff1[i] + diff2[i];
        max_val = max(max_val, ans_i);
        XOR ^= ans_i;
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        ll l, r, s, e;
        scanf("%lld %lld %lld %lld", &l, &r, &s, &e);
        diff(l, r, s, e, (s - e) / (r - l));
    }
    sum();
    printf("%lld %lld", XOR, max_val);
    return 0;
}

