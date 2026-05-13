// Problem:  Luogu P5731 【深基5.习6】蛇形方阵
// Link:     https://www.luogu.com.cn/problem/P5731
// Author:   nine19een
// Date:     2025-10-24

#include<stdio.h>

int n, a[15][15];

int main() {
    scanf("%d", &n);
    int N = n * n, i = 1;
    int x = 1, y = 1;
    a[1][1] = i++;
    while (i <= N) {
        while (y < n && a[x][y + 1] == 0) {
            a[x][++y] = i++;
        }
        while (x < n && a[x + 1][y] == 0) {
            a[++x][y] = i++;
        }
        while (y > 1 && a[x][y - 1] == 0) {
            a[x][--y] = i++;
        }
        while (x > 1 && a[x - 1][y] == 0) {
            a[--x][y] = i++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
