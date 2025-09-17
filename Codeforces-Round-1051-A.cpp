// Problem:  Codeforces Round 1051 All Lengths Subtraction
// Link:     https://codeforces.com/contest/2143/problem/A
// Author:   nine19een
// Date:     2025-09-17

#include<bits/stdc++.h>
using namespace std;

int t;

void OP(){
	int n, idx;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == n){
			idx = i;
		}
	}
	int l = idx, r = idx;
	for(int i = 1; i <= n; ++i){
		if(l - 1 >= 0 && a[l - 1] == a[idx] - 1){
			for(int j = l; j <= r; ++j){
				a[j]--;
			}
			l--;
			continue;
		}
		if(r + 1 < n && a[r + 1] == a[idx] - 1){
			for(int j = l; j <= r; ++j){
				a[j]--;
			}
			r++;
			continue;
		}
		if(l == 0 && r == n - 1){
			cout << "YES" << '\n';
			return;
		}
		cout << "NO" << '\n';
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		OP();
	}
	return 0;
}
