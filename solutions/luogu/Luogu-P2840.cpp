// Problem:  Luogu P2840 纸币问题 2
// Link:     https://www.luogu.com.cn/problem/P2840
// Author:   nine19een
// Date:     2025-07-19

#include<bits/stdc++.h>
using namespace std;
int n, w;
int const maxn = 1e4 + 5;
int money[maxn] = {0};

long long solve(int money[], int w){
	long long f[maxn] = {0};
	long long const hash = 1e9 + 7;
	f[0] = 1;
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= n; j++){
			if(i >= money[j]){
				f[i] = (f[i] + f[i - money[j]]) % hash;
			}
		}
	}
	return f[w] % hash;
}

int main(){
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		cin >> money[i];
	}
	cout << solve(money, w);
	return 0;	
}
