// Problem:  Luogu P1060 [NOIP 2006 普及组] 开心的金明
// Link:     https://www.luogu.com.cn/problem/P1060
// Author:   nine19een
// Date:     2025-10-28

#include<bits/stdc++.h>
using namespace std;
int const maxn = 3e4 + 5;

struct Items{
	int val, imp;
};

int dp[maxn], n, m, ans;
Items item[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		cin >> item[i].val >> item[i].imp;
	}
	for(int i = 1; i <= m; ++i){
		for(int j = n; j >= 0; --j){
			if(j - item[i].val < 0){
				continue;
			}
			dp[j] = max(dp[j], dp[j - item[i].val] + item[i].val * item[i].imp);
		}
	}
	cout << dp[n];
	return 0;
}
