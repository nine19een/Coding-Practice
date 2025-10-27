// Problem:  Luogu P5722 【深基4.例11】数列求和
// Link:     https://www.luogu.com.cn/problem/P5722
// Author:   nine19een
// Date:     2025-10-27

#include<stdio.h>

int n, cnt;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		cnt += i;
	}
	printf("%d", cnt);
	return 0;
}
