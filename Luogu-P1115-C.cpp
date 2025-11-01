// Problem:  Luogu P1115 最大子段和
// Link:     https://www.luogu.com.cn/problem/P1115
// Author:   nine19een
// Date:     2025-11-02

#include<stdio.h>
#define ll long long
#define maxn 200005

ll max(ll x, ll y) {
    return x > y ? x : y;
}

ll n, a[maxn], dp[maxn], ans = -1e9;

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf(" %lld", &a[i]);
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    printf("%lld", ans);
    return 0;
}