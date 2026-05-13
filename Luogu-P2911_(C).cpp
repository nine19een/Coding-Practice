// Problem:  Luogu P2911 [USACO08OCT] Bovine Bones G
// Link:     https://www.luogu.com.cn/problem/P2911
// Author:   nine19een
// Date:     2025-10-26

#include<stdio.h>
#define maxn 85

int s1, s2, s3, cnt[maxn], ans_cnt, ans_i;

int main() {
    scanf("%d %d %d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                cnt[i + j + k]++;
            }
        }
    }
    for (int i = 1; i < maxn; ++i) {
        if (ans_cnt < cnt[i]) {
            ans_i = i;
            ans_cnt = cnt[i];
        }
    }
    printf("%d", ans_i);
    return 0;
}
