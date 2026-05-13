// Problem:  Luogu B2097 最长平台
// Link:     https://www.luogu.com.cn/problem/B2097
// Author:   nine19een
// Date:     2025-10-24

#include<stdio.h>
#define maxn 105

int n, a[maxn], cnt, ans;

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        cnt = (a[i] == a[i - 1]) ? cnt + 1 : 1;
        ans = ans > cnt ? ans : cnt;
    }
    printf("%d",ans);
}