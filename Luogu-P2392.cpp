// Problem:  Luogu P2392 kkksc03考前临时抱佛脚
// Link:     https://www.luogu.com.cn/problem/P2392
// Author:   nine19een
// Date:     2025-08-04

#include<bits/stdc++.h>
using namespace std;
int s[5], t[5], abcd[10][65], sum[5] = {0}, max_[5] = {0};
int T = 0;

int Solve(int sum, int s, int num[], int MAX){
	int const SIZE = sum + 5;
	int mid = sum / 2;
	if(MAX > mid){
		return MAX;
	}
	int dp[SIZE];
	for(int i = 1; i <= s; i++){
		for(int j = mid; j >= 0; j--){
			if(j == 0){
				dp[j] = mid;
				continue;
			}
			if(i == 1){
				if(j < num[1]){
					dp[j] = mid;
				}
				else{
					dp[j] = mid - num[1];
				}
				continue;
			}
			if(j < num[i]){
				continue;
			}
			if(j >= num[i]){
				dp[j] = min(dp[j], dp[j - num[i]] - num[i]);
				continue;
			}
		}
	}
	if(sum % 2 == 1){
		return (dp[mid] + 1 + mid);
	}
	if(sum % 2 == 0){
		return (mid + dp[mid]);
	}
}

int main(){
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= s[i]; j++){
			cin >> abcd[i][j];
			sum[i] += abcd[i][j];
			max_[i] = max(max_[i], abcd[i][j]);
		}
	}
	for(int i = 1; i <= 4; i++){
		if(s[i] == 1){
			t[i] = abcd[i][1];
		}
		else{
			t[i] = Solve(sum[i], s[i], abcd[i], max_[i]);
		}
		T += t[i];
	}
	cout << T;
	return 0;	
}
