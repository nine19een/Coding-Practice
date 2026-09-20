// Problem:  Luogu P2840 纸币问题 2
// Link:     https://www.luogu.com.cn/problem/P2840
// Author:   nine19een
// Date:     2025-11-04

#include<stdio.h>
#define ll long long
#define maxn 1005
#define maxm 10005
#define mod 1000000007

int n, w, a[maxn];
ll dp[maxm];

ll DP() {
    dp[0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n && a[j] <= w; j++) {
            dp[i] = (a[j] <= i) ? (dp[i] + dp[i - a[j]]) % mod : dp[i];
        }
    }
    return dp[w];
}

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }
    printf("%lld", DP());
    return 0;
}
