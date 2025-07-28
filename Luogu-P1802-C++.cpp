// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1802
// Author:   nine19een
// Date:     2025-07-29

#include <bits/stdc++.h>
using  namespace std;
int n, x;
long long ans, dpmax = 0;
int lose[1005], win[1005], use[1005];
long long dp[1005] = {0};
int main(){
	cin >> n >> x;
	if(n == 0){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> lose[i] >> win[i] >> use[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = x; j >= 0; j--){
			if(j - use[i] < 0){
				dp[j] += lose[i];
			}
			else{
				dp[j] = max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
			}
			dpmax = max(dpmax, dp[j]);
		}
	}
	ans = 5 * dpmax;
	cout << ans;	
	return 0;
}
