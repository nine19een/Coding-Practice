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
