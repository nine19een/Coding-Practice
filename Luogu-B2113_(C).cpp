// Problem:  Luogu B2113 输出亲朋字符串
// Link:     https://www.luogu.com.cn/problem/B2113
// Author:   nine19een
// Date:     2025-11-05

#include<stdio.h>
#include <string.h>

char str[105], ans[105];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            ans[i] = str[i] + str[0];
            break;
        }
        ans[i] = str[i] + str[i + 1];
    }
    printf("%s", ans);
}
