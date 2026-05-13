// Problem:  Luogu P1049 [NOIP 2001 普及组] 装箱问题
// Link:     https://www.luogu.com.cn/problem/P1049
// Author:   nine19een
// Date:     2025-07-31

#include<bits/stdc++.h>
using namespace std;
int V, n, sum = 0, mindp = 20005;
int v[35], dp[20005];

int main(){
	cin >> V >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		sum += v[i];
	}
	if(sum <= V){
		cout << V - sum;
		return 0;
	}
	for(int i = 0; i <= V; i++){
		dp[i] = i;
	}
	for(int i = 1; i <= n; i++){
		for(int j = V; j >= 0; j--){
			if(j - v[i] < 0){
				if(j == V){
					mindp = min(mindp, dp[j]);
				}
				continue;
			}	
			dp[j] = min(dp[j - v[i]], dp[j]);
			if(j == V){
				mindp = min(mindp, dp[j]);
				if(mindp == 0){
					cout << 0;
					return 0;
				}
			}
		}
	}
	cout << mindp;
	return 0;
}
