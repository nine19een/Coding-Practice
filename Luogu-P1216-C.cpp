// Problem:  Luogu P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
// Link:     https://www.luogu.com.cn/problem/P1216
// Author:   nine19een
// Date:     2025-10-30

#include<stdio.h>
#define maxn 1005

int a[maxn][maxn], dp[maxn][maxn], r;

int max(int x, int y) {
    return x > y ? x : y;
}

void DP() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        ans = max(ans, dp[r][i]);
    }
    printf("%d", ans);
}

int main() {
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf(" %d", &a[i][j]);
        }
    }
    DP();
    return 0;
}