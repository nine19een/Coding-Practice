// Problem:  Luogu P1616 疯狂的采药
// Link:     https://www.luogu.com.cn/problem/P1616
// Author:   nine19een
// Date:     2025-07-31

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e7 + 5;
int const maxm = 1e4 + 5;
int T, m;
long long dpmax = 0;
int v[maxm], t[maxm];
long long dp[maxn] = {0};

int main(){
	cin >> T >> m;
	for(int i = 1; i <= m; i++){
		cin >> t[i] >> v[i];
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= T; j++){
			if(j - t[i] < 0){
				if(j == T){
					dpmax = max(dp[j], dpmax);
				} 
				continue;
			}
			dp[j] = max(dp[j - t[i]] + v[i], dp[j]);
			if(j == T){
				dpmax = max(dp[j], dpmax);
			}
		}
	}
	cout << dpmax;
	return 0;
}
