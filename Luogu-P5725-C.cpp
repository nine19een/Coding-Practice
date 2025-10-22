// Problem:  Luogu P5725 【深基4.习8】求三角形
// Link:     https://www.luogu.com.cn/problem/P5725
// Author:   nine19een
// Date:     2025-10-222

#include<stdio.h>

int n;

int main() {
    scanf("%d",&n);
    int N = n * n;
    for (int i = 1; i <= N; i++) {
        printf("%02d", i);
        if (i % n == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
    int num = 1;
    for (int i = 1; i <= n; i++) {
        int cnt_space = (n - i) * 2;
        printf("%*s", cnt_space, "");
        int cnt = 0;
        while (cnt < i) {
            printf("%02d", num++);
            cnt++;
        }
        putchar('\n');
    }
    return 0;
}