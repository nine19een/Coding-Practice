// Problem:  Luogu B4289 [蓝桥杯青少年组省赛 2022] 字母组合
// Link:     https://www.luogu.com.cn/problem/B4289
// Author:   nine19een
// Date:     2025-10-29

#include<stdio.h>
#define maxn 105

int n;
char c[maxn];

void swap(char *ptr_x, char *ptr_y){
	char z = *ptr_x;
	*ptr_x = *ptr_y;
	*ptr_y = z; 
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf(" %c", &c[i]);
	}
	for(int i = 1; i <= n - 1; ++i){
		for(int j = 1; j <= n - i; ++j){
			if(c[j] > c[j + 1]){
				swap(&c[j], &c[j + 1]);
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		printf("%c", c[i]);
	}
	return 0;
}
