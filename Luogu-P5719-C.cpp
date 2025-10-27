// Problem:  Luogu P5719 【深基4.例3】分类平均
// Link:     https://www.luogu.com.cn/problem/P5719
// Author:   nine19een
// Date:     2025-10-27

#include<stdio.h>

int n, k;
double A, B;

void AB(){
	double cnt_a = 0, sum_a = 0, cnt_b = 0, sum_b = 0;
	for(int i = 1; i <= n; ++i){
		if(i % k == 0){
			cnt_a += 1;
			sum_a += i;
		}
		else{
			cnt_b += 1;
			sum_b += i;
		}
	}
	A = sum_a / cnt_a, B = sum_b / cnt_b;
}

int main(){
	scanf("%d %d", &n, &k);
	AB();
	printf("%0.1lf %0.1lf", A, B);
	return 0;
}
