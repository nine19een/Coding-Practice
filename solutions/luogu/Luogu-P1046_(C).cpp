// Problem:  Luogu P1046 [NOIP 2005 普及组] 陶陶摘苹果
// Link:     https://www.luogu.com.cn/problem/P1046
// Author:   nine19een
// Date:     2025-10-26

#include<stdio.h>

int apple[15], h, cnt;

int main() {
    for (int i = 1; i <= 10; ++i) {
        scanf("%d", &apple[i]);
    }
    scanf("%d", &h);
    h += 30;
    for (int i = 1; i <= 10; ++i) {
        cnt += h >= apple[i] ? 1 : 0;
    }
    printf("%d", cnt);
    return 0;
}