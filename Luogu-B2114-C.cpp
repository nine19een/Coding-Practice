// Problem:  Luogu B2114 配对碱基链
// Link:     https://www.luogu.com.cn/problem/B2114
// Author:   nine19een
// Date:     2025-11-06

#include<stdio.h>
#include <string.h>

char str[260];

void print(int len) {
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'A':
                printf("T");
                break;
            case 'T':
                printf("A");
                break;
            case 'C':
                printf("G");
                break;
            case 'G':
                printf("C");
                break;
        }
    }
}

int main() {
    scanf("%s", str);
    int len = strlen(str);
    print(len);
    return 0;
}
