// Problem:  Luogu P2834 纸币问题 3
// Link:     https://www.luogu.com.cn/problem/P2834
// Author:   nine19een
// Date:     2025-11-04

#include<stdio.h>
#define ll long long
#define mod 1000000007
#define maxn 1005
#define maxm 10005

int n, w, a[maxn];
ll dp[maxm];

ll DP(){
	dp[0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= w; ++j){
			dp[j] = a[i] <= j ? (dp[j] + dp[j - a[i]]) % mod : dp[j];
		}
	}
	return dp[w];	
}

int main(){
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= n; ++i){
		scanf(" %d", &a[i]);
	}
	printf("%lld", DP());
	return 0;
}
