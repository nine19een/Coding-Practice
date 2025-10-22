// Problem:  Luogu P3916 图的遍历
// Link:     https://www.luogu.com.cn/problem/P3916
// Author:   nine19een
// Date:     2025-10-22

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;

int n, m, ans[maxn];
vector<int> node[maxn];

void DFS(int idx_max, int idx){
	ans[idx] = idx_max;
	for(int p : node[idx]){
		if(!ans[p]){
			DFS(idx_max, p);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int out_d, idx;
		cin >> out_d >> idx;
		node[idx].push_back(out_d);
	}
	for(int i = n; i >= 1; --i){
		if(!ans[i]){
			DFS(i, i);	
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}
	return 0;
}
