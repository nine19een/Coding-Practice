// Problem:  Luogu P1047 [NOIP 2005 普及组] 校门外的树
// Link:     https://www.luogu.com.cn/problem/P1047
// Author:   nine19een
// Date:     2025-07-15

#include <bits/stdc++.h>
using namespace std;
int l, m, cnt = 0;
int const maxn = 1e4 + 5;
int left_[maxn], right_[maxn], tree[maxn];
int main(){
	cin >> l >> m;
	memset(tree, 0, sizeof(tree));
	for(int i = 0; i <= l; i++){
		tree[i] = 1;
	}
	for(int i = 1; i <= m; i++){
		cin >> left_[i] >> right_[i];
	}
	for(int i = 1; i <= m; i++){
		for(int j = left_[i]; j <= right_[i]; j++){
			tree[j] = 0;
		}
	}
	for(int i = 0; i <= l; i++){
		if(tree[i] == 1){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
