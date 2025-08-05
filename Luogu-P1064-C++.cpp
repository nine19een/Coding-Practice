// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1064
// Author:   nine19een
// Date:     2025-08-06

#include<bits/stdc++.h>
using namespace std;
struct Package{
	int value, sum;
};
int n, m, cnt_package = 0;
Package small[65][65];
vector<Package>big[65];

bool Store(vector<int>&r, int s){
	for(int p : r){
		if(s == p){
			return false;
		}
	}
	return true;
}

void Smallpackage(int cnt, Package p[]){
	int const N = n - p[0].value + 5;
	int dp[N] = {0};
	for(int i = 0; i <= cnt; i++){
		if(i == 0){
			for(int j = 0; j <= n - p[0].value; j += 10){
				dp[j] = p[0].sum;
			}	
			continue;
		}
		for(int j = n - p[0].value; j >= 0; j -= 10){
			if(j - p[i].value < 0){
				continue;
			}
			dp[j] = max(dp[j], dp[j - p[i].value] + p[i].sum);
		}
	}
	vector<int>Return;
	cnt_package++;
	for(int i = 0; i <= n - p[0].value; i += 10){
		if(Store(Return, dp[i])){
			Return.push_back(dp[i]);
			Package b = {i + p[0].value, dp[i]};
			big[cnt_package].push_back(b);
		}
	}
	return;
}

int main(){
	memset(small, 0, sizeof(small));
	cin >> n >> m;
	const int maxn = n + 5;
	int DP[maxn] = {0};
	int cnt[65];
	for(int j = 1; j <= 60; j++){
		cnt[j] = 1;
	}
	for(int i = 1; i <= m; i++){
		int vv, pp, qq;
		cin >> vv >> pp >> qq;
		if(vv == 0){
			continue;
		}
		if(qq == 0){
			if(vv > n){
				continue;
			}
			small[i][0] = {vv, vv * pp};
			continue;
		}
		small[qq][cnt[qq]] = {vv, vv * pp};
		cnt[qq]++;
	}
	for(int i = 1; i <= m; i++){
		if(small[i][0].value == 0 && small[i][0].sum == 0){
			continue;
		}
		if(small[i][1].value == 0 && small[i][1].sum == 0){
			cnt_package++;
			big[cnt_package].push_back(small[i][0]);
			continue;
		}
		Smallpackage(cnt[i] - 1, small[i]);
	}
	if(cnt_package == 0){
		cout << 0;
		return 0;
	}
	for(int k = 1; k <= cnt_package; k++){
		for(int j = n; j >= 0; j -= 10){
			for(Package i : big[k]){
				if(j - i.value < 0){
					continue;
				}
				DP[j] = max(DP[j], DP[j - i.value] + i.sum);
			}
		}		
	}
	cout << DP[n];
	return 0;
}
