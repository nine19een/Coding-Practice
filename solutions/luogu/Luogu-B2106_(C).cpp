// Problem:  Luogu B2106 矩阵转置
// Link:     https://www.luogu.com.cn/problem/B2106
// Author:   nine19een
// Date:     2025-10-26

#include<stdio.h>
#define maxn 105

int n, m, a[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %d", &a[i][j]);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
