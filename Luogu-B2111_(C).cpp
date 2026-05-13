// Problem:  Luogu B2111 基因相关性
// Link:     https://www.luogu.com.cn/problem/B2111
// Author:   nine19een
// Date:     2025-11-03

#include<stdio.h>
#include <string.h>
#define maxn 505

double limit_proportion;
int cnt;
char dna_1[maxn], dna_2[maxn];

int main() {
    scanf("%lf", &limit_proportion);
    scanf(" %s %s", dna_1, dna_2);
    int len = strlen(dna_1);
    for(int i = 0; i < len; i++) {
        cnt += dna_1[i] == dna_2[i] ? 1 : 0;
    }
    double proportion = (double) cnt / (double) len;
    if(proportion >= limit_proportion) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}