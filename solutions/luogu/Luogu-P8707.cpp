// Problem:  Luogu P8707 [蓝桥杯 2020 省 AB1] 走方格
// Link:     https://www.luogu.com.cn/problem/P8707
// Author:   nine19een
// Date:     2025-09-11

#include<bits/stdc++.h>
using namespace std;

int n, m, dp[35][35];

bool cantVisit(int x, int y){
	return (!(x & 1) && !(y & 1));
}

void updateDP(int i, int j){
	if(i == 1 && j == 1){
		dp[i][j] = 1;
		return;
	}
	int dp_up = (i > 1) ? dp[i - 1][j] : 0;
	int dp_left = (j > 1) ? dp[i][j - 1] : 0;
	dp[i][j] = dp_up + dp_left;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(!cantVisit(i, j)){
				updateDP(i, j);
			}
		}
	}
	cout << dp[n][m];
	return 0;
} 
