// Problem:  Codeforces Round 1059 C. Beautiful XOR
// Link:     https://codeforces.com/contest/2162/problem/C
// Author:   nine19een
// Date:     2025-10-19

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

ll msb(ll x){
	return 63 - __builtin_clzll(x);
}

void op(){
	ll a, b, c, x1, x2;
	cin >> a >> b;
	if(msb(a) < msb(b)){
		cout << -1 << '\n';
		return;
	}
	c = (1 << (msb(a) + 1)) - 1;
	x1 = a ^ c;
	x2 = b ^ c;
	cout << 2 << '\n' << x1 << " " << x2 << '\n';
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
