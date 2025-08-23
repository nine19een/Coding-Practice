// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2251
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 5;
int N, M, a[maxn], st[maxn][25];

int Query(int i, int f, int len){
	return min(st[i + 1 - M][f], st[i - len + 1][f]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= N; ++i){
		st[i][0] = a[i];
	}
	int max_j = log2(M), f_len = 1 << max_j;
	for(int j = 1; j <= max_j; ++j){
		int max_i = N + 1 - (1 << j);
		for(int i = 1; i <= max_i; ++i){
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	int floor_M = log2(M);
	for(int i = M; i <= N; ++i){
		cout << Query(i, floor_M, f_len) << '\n';
	}
	return 0;
}
