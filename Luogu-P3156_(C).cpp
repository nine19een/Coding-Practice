// Problem:  Luogu P3156 【深基15.例1】询问学号
// Link:     https://www.luogu.com.cn/problem/P3156
// Author:   nine19een
// Date:     2025-11-01

#include<stdio.h>
#define maxn 2000005

int a[maxn], m, n;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf(" %d", &a[i]);
	}
	for(int i = 1; i <= m; ++i){
		int idx;
		scanf(" %d", &idx);
		printf("%d\n", a[idx]);
	}
	return 0;
}
