// Problem:  Luogu P3842 [TJOI2007] 线段
// Link:     https://www.luogu.com.cn/problem/P3842
// Author:   nine19een
// Date:     2025-08-05

#include <bits/stdc++.h>
using namespace std;
int const maxn = 2e4 + 5;
int dp[2];
int n, dpl, dpr;
struct Line{
	int l, r;
};
Line line[maxn];

int DP(int i, int leftORright){
	int walk = 0;
	if(i == 1){
		if(leftORright == 0){
			walk = 2 * line[i].r - 1 - line[i].l;
		}
		if(leftORright == 1){
			walk = line[i].r - 1;
		}
		return walk;
	}
	if(leftORright == 0){
		walk = min(dp[0] + abs(line[i - 1].l - line[i].r) + line[i].r - line[i].l, dp[1] + abs(line[i - 1].r - line[i].r) + line[i].r - line[i].l);
	}
	if(leftORright == 1){
		walk = min(dp[0] + abs(line[i - 1].l - line[i].l) + line[i].r - line[i].l, dp[1] + abs(line[i - 1].r - line[i].l) + line[i].r - line[i].l);
	}
	return walk;
}

int main(){
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> line[i].l >> line[i].r;
		if(i == n){
			line[i].r = n;
		}
	}
	for(int i = 1; i <= n; i++){
		if(i == n){
			dp[1] = DP(i, 1);
			cout << dp[1] + n - 1;
			return 0;
		}
		dpl = DP(i, 0);
		dpr = DP(i, 1);
		dp[0] = dpl;
		dp[1] = dpr;
	}
	cout << dp[1] + n - 1;
	return 0;
} 
