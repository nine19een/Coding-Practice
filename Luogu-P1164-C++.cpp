// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1164
// Author:   nine19een
// Date:     2025-08-01

#include<bits/stdc++.h>
using namespace std;
int N, M;
int dp[10005] = {0}, a[105];

int main(){
	cin >> N >> M;
	for(int i= 1; i <= N; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= N; i++){
		for(int j = M; j >= 0; j--){
			if(j == 0){
				dp[j] = 1;
				continue;
			}
			if(i == 0 && j != 0){
				dp[j] = 0;
				continue;
			}
			if(j == a[i]){
				dp[j] += 1;
				continue;
			}
			if(a[i] > j){
				continue;
			}
			if(a[i] < j){
				dp[j] += dp[j - a[i]];
			}
		}
	}
	cout << dp[M];
	return 0;
}
