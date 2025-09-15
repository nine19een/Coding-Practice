// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1179
// Author:   nine19een
// Date:     2025-09-15

#include<stdio.h>

int l, r;

int cnt_2(int x, int* ans_ptr){
	while(x != 0){
		int single_num = x % 10;
		(*ans_ptr) += (single_num == 2) ? 1 : 0;
		x /= 10;
	}
}

int cnt(int l, int r){
	int ans = 0;
	for(int i = l; i <= r; ++i){
		cnt_2(i, &ans);
	}
	return ans;
}

int main(){
	scanf("%d %d", &l, &r);
	printf("%d", cnt(l, r));
	return 0;
}
