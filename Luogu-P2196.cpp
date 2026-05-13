// Problem:  Luogu P2196 [NOIP 1996 提高组] 挖地雷
// Link:     https://www.luogu.com.cn/problem/P2196
// Author:   nine19een
// Date:     2025-07-23

#include<bits/stdc++.h>
using namespace std;
int n, maxdpj, idx, maxdp, ans;
int boom[25], connect[25][25], dp[25] = {0}, front[25] = {0};

void INVERT(int i){
	if(front[i] != 0){
		INVERT(front[i]);
	}
	cout << i << " ";
	return;
}

void DIG(){
	dp[1] = boom[1];
	maxdp = boom[1];
	ans = 1;
	for(int i = 2; i <= n; i++){
		maxdpj = 0, idx = 0;
		for(int j = 1; j < i; j++){
			if(connect[j][i] == 1 && dp[j] > maxdpj){
				maxdpj = dp[j];
				idx = j;
			}
		}
		dp[i] = boom[i] + maxdpj;
		front[i] = idx;
		if(dp[i] > maxdp){
			maxdp = dp[i];
			ans = i;
		}
	}
	return;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> boom[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			cin >> connect[i][j];
		}
	}
	DIG();
	INVERT(ans);
	cout << endl << maxdp;
	return 0;
} 
