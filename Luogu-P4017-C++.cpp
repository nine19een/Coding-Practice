// Problem:  Luogu P4017 最大食物链计数
// Link:     https://www.luogu.com.cn/problem/P4017
// Author:   nine19een
// Date:     2025-07-28

#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
vector<int>animals[5005];
int IN[5005] = {0}, OUT[5005] = {0}, dp[5005] = {0};

void search(int i, vector<int>&a){
	if(OUT[i] == 0){
		dp[i] = 1;
		return;
	}
	for(int p : a){
		if(dp[p] == 0){
			search(p, animals[p]);
		}
		dp[i] =(dp[i] + dp[p]) % 80112002;
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		animals[a].push_back(b);
		IN[b]++;
		OUT[a]++;
	}
	for(int i = 1; i <= n; i++){
		if(IN[i] == 0){
			search(i, animals[i]);
			cnt = (cnt + dp[i]) % 80112002;
		}
	}
	cout << cnt;
	return 0;
}
