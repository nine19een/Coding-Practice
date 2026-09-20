// Problem:  Luogu B2099 矩阵交换行
// Link:     https://www.luogu.com.cn/problem/B2099
// Author:   nine19een
// Date:     2025-10-31

#include<stdio.h>

int a[10][10], m, n;

int main() {
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }
    scanf(" %d %d", &m, &n);
    for (int i = 1; i <= 5; ++i) {
        int I = i;
        if (i == m) {
            I = n;
        }
        if (i == n) {
            I = m;
        }
        for (int j = 1; j <= 5; ++j) {
            printf("%d ", a[I][j]);
        }
        putchar('\n');
    }
    return 0;
}
