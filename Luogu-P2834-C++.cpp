// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2834
// Author:   nine19een
// Date:     2025-07-19

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e4 + 5;
int n, w;
int money[maxn] = {0};
int f[maxn][maxn];

int solve(){
	int const hash = 1e9 + 7;
	for(int i = 1; i <= n; i++){
		f[i][0] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			if(money[i] > j){
				f[i][j] = 0;
			}
			else if(money[i] < j){
				f[i][j] = (f[i][j - money[i]]) % hash;
			}
			else{
				f[i][j] = 1;
			}
			f[i][j] = (f[i][j] + f[i - 1][j]) % hash;
		}
	}
	int I = 0;
	for(int i = 1; i <= n; i++){
		if(money[i] <= w){
			I = i;
		}
	}
	return f[I][w];
}

int main(){
	memset(f, 0, sizeof(f));
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		cin >> money[i];
	}
	if(w == 0){
		cout << 0;
		return 0;
	}
	cout << solve();
	return 0;
}
