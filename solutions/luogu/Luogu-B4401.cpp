// Problem:  Luogu B4401 [蓝桥杯青少年组国赛 2025] 第六题
// Link:     https://www.luogu.com.cn/problem/B4401
// Author:   nine19een
// Date:     2025-10-29

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 1e7 + 5, MOD = 1e9 + 7;

ll h, w, grid[maxn], cnt, dp_f[maxn], dp_t[maxn];

bool is11multi(ll x){
	return (x % 11 == 0);
}

void initialize(ll hw){
	for(ll i = 1; i <= w; ++i){
		dp_f[i] = 1;
		dp_t[i] = (is11multi(grid[i]) || dp_t[i - 1]) ? 1 : 0;
	}
	for(ll i = w + 1; i <= hw; i += w){
		dp_f[i] = 1;
		dp_t[i] = (is11multi(grid[i]) || dp_t[i - w]) ? 1 : 0;
	}	
}

void DP(ll hw){
	for(int i = w + 2; i <= hw; ++i){
		if(dp_f[i]){
			continue;
		}
		dp_f[i] = ((dp_f[i - 1] % MOD) + (dp_f[i - w] % MOD)) % MOD;
		if(is11multi(grid[i])){
			dp_t[i] = ((dp_f[i - 1] % MOD) + (dp_f[i - w] % MOD)) % MOD;
		}
		else{
			dp_t[i] = ((dp_t[i - 1] % MOD) + (dp_t[i - w] % MOD)) % MOD;
		}
	}
	cout << dp_t[hw];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	ll hw = h * w;
	for(ll i = 1; i <= hw; ++i){
		cin >> grid[i];
	}
	initialize(hw);
	DP(hw);
	return 0;
}
