// Problem:  Luogu P1890 gcd区间
// Link:     https://www.luogu.com.cn/problem/P1890
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e3 + 5;
int n, m, a[maxn], st[maxn][15];

int gcd(int x, int y){
	return y == 0 ? x : gcd(y, x % y);
}

int query(int l, int r){
	int f = log2(r - l + 1);
	int len = 1 << f;
	return gcd(st[l][f], st[r - len + 1][f]); 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int max_j = log2(n);
	for(int i = 1; i <= n; ++i){
		st[i][0] = a[i];
	}
	for(int j = 1; j <= max_j; ++j){
		int max_i = n + 1 - (1 << j);
		for(int i = 1; i <= max_i; ++i){
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}
	int left, right;
	for(int i = 1; i <= m; ++i){
		cin >> left >> right;
		cout << query(left, right) << '\n';
	}
	return 0;
}
