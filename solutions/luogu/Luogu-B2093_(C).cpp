// Problem:  Luogu B2093 查找特定的值
// Link:     https://www.luogu.com.cn/problem/B2093
// Author:   nine19een
// Date:     2025-10-29

#include<stdio.h>
#define maxn 10005
#define maxm 20005

int n, a[maxn], aim_num;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf(" %d", &a[i]);
	}
	scanf(" %d", &aim_num);
	for(int i = 0; i < n; ++i){
		if(a[i] == aim_num){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
