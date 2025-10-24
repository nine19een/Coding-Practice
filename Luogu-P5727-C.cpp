// Problem:  Luogu P5727 【深基5.例3】冰雹猜想
// Link:     https://www.luogu.com.cn/problem/P5727
// Author:   nine19een
// Date:     2025-10-24

#include <stdio.h>
#define maxn 10000 

int n, a[maxn];

int isEven(int x){
	return !(x & 1);
}

int main(){
	scanf("%d", &n);
	a[0] = n;
	int i = 0;
	while(n != 1){
		if(isEven(n)){
			n >>= 1;
			a[++i] = n;
		}
		else{
			n = n * 3 + 1;
			a[++i] = n;
		}
	}
	for(; i >= 0; --i){
		printf("%d ", a[i]);
	}
	return 0;
}


