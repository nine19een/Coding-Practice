// Problem:  Luogu B2110 找第一个只出现一次的字符
// Link:     https://www.luogu.com.cn/problem/B2110
// Author:   nine19een
// Date:     2025-11-02

#include<stdio.h>
#include <string.h>

char cnt_lectter[30], c[1105];

int main() {
    scanf("%s", c);
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        cnt_lectter[c[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (cnt_lectter[c[i] - 'a'] == 1) {
            printf("%c", c[i]);
            return 0;
        }
    }
    printf("no");
    return 0;
}