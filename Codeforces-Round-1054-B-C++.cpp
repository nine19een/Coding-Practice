// Problem:  Codeforces Round 1054 B. Unconventional Pairs
// Link:     https://codeforces.com/contest/2149/problem/B
// Author:   nine19een
// Date:     2025-10-03

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op(){
	int n;
	ll max_ans = 0;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; ++i){
		max_ans = max(max_ans, abs(a[i] - a[i + 1]));
		i++;
	}
	cout << max_ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		op();
	}
	return 0;
}
