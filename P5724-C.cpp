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
