// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2367
// Author:   nine19een
// Date:     2025-08-16

#include<bits/stdc++.h>
using namespace std;
int const maxn = 5e6 + 5;
int const maxm = 1e9 + 5;

int n, p, x, y, z, ans = maxm;
int a[maxn], diff[maxn];

int main(){
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
	}
	for(int i = 1; i <= p; i++){
		cin >> x >> y >> z;
		diff[x] += z;
		diff[y + 1] -= z;
	}
	for(int i = 1; i <= n; i++){
		diff[i] += diff[i - 1];
		ans = min(ans, diff[i]);
	}
	cout << ans;
	return 0;
}
