// Problem:  Luogu P1048 [NOIP 2005 普及组] 采药
// Link:     https://www.luogu.com.cn/problem/P1048
// Author:   nine19een
// Date:     2025-11-05

#include <stdio.h>

int dp[1005], T, M, time[105], val[105];

int max(int x, int y){
	return x > y ? x : y;
}

int DP(){
	for(int i = 1; i <= M; ++i){
		for(int j = T; j >= 1; --j){
			if(time[i] > j){
				break;
			}
			dp[j] = max(dp[j], dp[j - time[i]] + val[i]);
		}
	}
	return dp[T];
}

int main(){
	scanf("%d %d", &T, &M);
	for(int i = 1; i <= M; ++i){
		scanf(" %d %d", &time[i], &val[i]);
	}
	printf("%d", DP());
	return 0;
}
