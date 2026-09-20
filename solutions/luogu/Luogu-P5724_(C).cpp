// Problem:  Luogu P5724 【深基4.习5】求极差 / 最大跨度值 / 最大值和最小值的差
// Link:     https://www.luogu.com.cn/problem/P5724
// Author:   nine19een
// Date:     2025-10-28

#include<stdio.h>

int n, min_num = 1e9, max_num;

int max(int x, int y){
	return (x > y) ? x : y;
}

int min(int x, int y){
	return (x < y) ? x : y;
}

int main(){
	scanf("%d", &n);	
	for(int i = 1; i <= n; ++i){
		int num;
		scanf("%d", &num);
		min_num = min(min_num, num);
		max_num = max(max_num, num);
	}
	printf("%d", max_num - min_num);
	return 0;
}
