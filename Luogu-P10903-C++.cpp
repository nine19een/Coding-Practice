// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P10903
// Author:   nine19een
// Date:     2025-09-06

#include<bits/stdc++.h>
using namespace std;

struct OP{
	int l, r;
};

int const maxn = 3e5 + 5;
int n, m, a[maxn], diff[maxn], cnt;
OP op[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		cin >> op[i].l >> op[i].r;
		diff[op[i].l]++;
		diff[op[i].r + 1]--;
	}
	for(int i = 1; i <= n; ++i){
		a[i] = a[i - 1] + diff[i];
		if(a[i] == 0){
			cnt++;
		}
	}
	for(int i = 1; i <= m; ++i){
		int ans = cnt;
		for(int j = op[i].l; j <= op[i].r; ++j){
			if(a[j] == 1){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

