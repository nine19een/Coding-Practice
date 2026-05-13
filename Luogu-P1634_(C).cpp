// Problem:  Luogu P1634 禽兽的传染病
// Link:     https://www.luogu.com.cn/problem/P1634
// Author:   nine19een
// Date:     2025-10-26

#include<stdio.h>
#define ll long long

ll x, n, cnt = 1;

int main() {
    scanf("%d %d", &x, &n);
    while(n--) {
        cnt *= x + 1;
    }
    printf("%lld", cnt);
    return 0;
}