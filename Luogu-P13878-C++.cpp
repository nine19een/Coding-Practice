// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P13878
// Author:   nine19een
// Date:     2025-09-08

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct S{
	ll a, b;
};

int maxn = 1e5 + 5;
int n, avg, cnt_num[15], cnt_change[15];
ll ans;
vector<ll> v[15];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	for(int i = 0; i <= 9; ++i){
		v[i].reserve(maxn);
	}
	cin >> n;
	avg = n / 10;
	for(int i = 1; i <= n; ++i){
		ll a, b;
		cin >> a >> b;
		v[a].push_back(b);
		cnt_num[a]++;
	}
	for(int i = 0; i <= 9; ++i){
		sort(v[i].begin(), v[i].end());
		if(cnt_num[i] >= avg){
			cnt_change[i] = cnt_num[i] - avg;
		}
	}
	for(int i = 0; i <= 9; ++i){
		if(cnt_change[i] != 0){
			for(int j = 0; j < cnt_change[i]; ++j){
				ans += v[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}
