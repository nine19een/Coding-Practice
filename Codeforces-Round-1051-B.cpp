// Problem:  Codeforces Round 1051 B. Discounts
// Link:     https://codeforces.com/contest/2143/problem/B
// Author:   nine19een
// Date:     2025-09-17

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void buy(){
	int n, k;
	ll ans = 0;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> b(k);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < k; ++i){
		cin >> b[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	while(1){
		if(j == k || b[j] > n - i || i == n){
			for(int p = i; p < n; ++p){
				ans += a[p];
			}
			cout << ans << '\n';
			return;
		}
		else{
			while(--b[j]){
				ans += a[i++];
			}
			i++;
			j++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		buy();
	}
	return 0;
}
