// Problem:  Luogu P8683 [蓝桥杯 2019 省 B] 后缀表达式
// Link:     https://www.luogu.com.cn/problem/P8683
// Author:   nine19een
// Date:     2025-09-14

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ll_min = 1e9 + 5;
ll n, m, ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	ll A = n + m + 1;
	vector<ll> a(A);
	if(m == 0){
		for(ll i = 0; i < A; ++i){
			cin >> a[i];
			ans += a[i];
		}
		cout << ans;
		return 0;
	}
	for(ll i = 0; i < A; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	A--;
	for(int i = 1; i < A; ++i){
		ans += abs(a[i]);
	}
	ans = a.front() + ans - a.back();
	cout << ans;
	return 0;
}
