// Problem:  Luogu P1077 [NOIP 2012 普及组] 摆花
// Link:     https://www.luogu.com.cn/problem/P1077
// Author:   nine19een
// Date:     2025-08-04

#include<bits/stdc++.h>
using namespace std;
int const Hash = 1e6 + 7;
int n, m;
int a[105] = {0}, dp[105] = {0};
 
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= m; i++){
		if(i <= a[1]){
			dp[i] = 1;
			continue;
		}
		dp[i] = 0;
	}
	for(int i = 2; i <= n; i++){
		for(int j = m; j >= 0; j--){
			int dpj = 0;
			if(j == 0){
				continue;
			}
			if(j > a[i]){
				for(int k = 0; k <= a[i]; k++){
					dpj = (dpj + dp[j - k]) % Hash;
				} 
				dp[j] = dpj;
				continue;
			}
			for(int k = 0; k <= j; k++){
				dpj = (dpj + dp[j - k]) % Hash;
			}
			dp[j] = dpj;
		}
	}
	cout << dp[m];
	return 0;
}
