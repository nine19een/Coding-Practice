// Problem:  Luogu B2098 整数去重
// Link:     https://www.luogu.com.cn/problem/B2098
// Author:   nine19een
// Date:     2025-10-30

#include<stdio.h>
#define maxn 20005

int n, a[maxn], num[105];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (num[a[i]]) {
            continue;
        }
        printf("%d ", a[i]);
        num[a[i]]++;
    }
    return 0;
}
