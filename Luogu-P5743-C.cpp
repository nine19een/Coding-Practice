// Problem:  洛谷 P5743 【深基7.习8】猴子吃桃
// Link:     https://www.luogu.com.cn/problem/P5743
// Author:   nine19een
// Date:     2025-09-15

#include<stdio.h>

int n;

int main(){
	scanf("%d", &n);
	int peach = 1;
	while(--n){
		peach++;
		peach *= 2;
	}
	printf("%d", peach);
}
