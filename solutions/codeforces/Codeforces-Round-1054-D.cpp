// Problem:  Codeforces Round 1054 D. A and B
// Link:     https://codeforces.com/contest/2149/problem/D
// Author:   nine19een
// Date:     2025-10-05

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op(){
	ll n, L_a, L_b, cnt_a = 0, cnt_b = 0, ans_a = 0, ans_b = 0;
	string s;
	cin >> n >> s;
	vector<ll> a, b;
	a.reserve(n + 5);
	b.reserve(n + 5);
	for(int i = 0; i < n; ++i){
		switch(s[i]){
			case 'a':{
				a.push_back(i - cnt_a++);
				break;
			}
			case 'b':{
				b.push_back(i - cnt_b++);				
				break;
			}
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	L_a = a[a.size() / 2];
	L_b = b[b.size() / 2];
	for(ll p : a){
		ans_a += abs(p - L_a);
	}
	for(ll p : b){
		ans_b += abs(p - L_b);
	}
	cout << min(ans_a, ans_b) << '\n';
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
