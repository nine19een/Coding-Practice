// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P10900
// Author:   nine19een
// Date:     2025-08-22

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll const maxn = 2e5 + 5, maxm = 1e16 + 5;
ll n, cnt;
vector<ll>a;

ll lowbit(ll num){
	return num & -num;
}

void isPoet(ll num){
	if(lowbit(num) != num){
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	a.reserve(maxn);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		ll ai;
		cin >> ai;
		a.push_back(ai);		
	}
	for(ll p : a){
		isPoet(p);
	}
	cout << n - cnt;
	return 0;
}
