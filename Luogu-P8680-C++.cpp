// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P8680
// Author:   nine19een
// Date:     2025-09-12

#include<stdio.h>

int Match(int single_num){
	return (single_num == 2 || single_num == 0 || single_num == 1 || single_num == 9);
}

void CNT(int x, long long* sum_ptr){
	int X = x;
	while(x != 0){
		int mol = x % 10;
		if(Match(mol)){
			(*sum_ptr) += X;
			break;
		}
		x /= 10;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0;
	while(n){
		CNT(n--, &sum);
	}
	printf("%lld", sum);
	return 0;
}
