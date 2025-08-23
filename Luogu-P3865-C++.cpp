// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P3865
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 5, maxm = 2e6 + 5 ;
int N, M, a[maxn], st[maxn][35];

int Query(int l, int r){
	int f = log2(r - l + 1), len = 1 << f;
	return max(st[l][f], st[r - len + 1][f]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
	}
	int st_len = log2(N);
	for(int j = 0; j <= st_len; ++j){
		int max_i = N + 1 - (1 << j);
		for(int i = 1; i <= max_i; ++i){
			if(j == 0){
				st[i][j] = a[i];
			}
			else{
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int l, r;
	for(int i = 1; i <= M; ++i){
		cin >> l >> r;
		cout << Query(l, r) << '\n';
	}
	return 0;
}
