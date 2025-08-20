// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P12280
// Author:   nine19een
// Date:     2025-08-21

#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 5;

int n, ans = maxn, a[maxn];
bool b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int l = 1, r = n;
	while(l <= n && !b[a[l]]){
		b[a[l++]] = true;
	}
	while(r && !b[a[r]]){
		b[a[r--]] = true;
	}
	while(l){
		ans = min(ans, r - l + 1);
		b[a[--l]] = false;
		while(r && !b[a[r]]){
			b[a[r--]] = true;
		}
	}
	cout << n - ans;
	return 0;
}
