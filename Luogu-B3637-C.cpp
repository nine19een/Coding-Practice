// Problem:  Luogu B3637 最长上升子序列
// Link:     https://www.luogu.com.cn/problem/B3637
// Author:   nine19een
// Date:     2025-10-31

#include<stdio.h>
#define maxn 5005

int max(int x, int y) {
    return (x > y ? x : y);
}

int n, a[maxn], dp[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int idx;
        scanf("%d", &a[i]);
        for (int j = 1; j < i; ++j) {
            dp[i] = a[i] > a[j] ? max(dp[i], dp[j] + 1) : dp[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d", ans + 1);
    return 0;
}