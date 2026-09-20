// Problem:  Codeforces Round 1059 A. Beautiful Average
// Link:     https://codeforces.com/contest/2162/problem/A
// Author:   nine19een
// Date:     2025-10-17

#include<bits/stdc++.h>
using namespace std;

int t;

void op(){
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		ans = max(ans, num);
	}
	cout << ans << '\n';
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
