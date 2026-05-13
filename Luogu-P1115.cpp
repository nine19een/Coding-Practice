// Problem:  Luogu P1115 最大子段和
// Link:     https://www.luogu.com.cn/problem/P1115
// Author:   nine19een
// Date:     2025-07-28

#include <bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;
int const minn = -1e9 - 5;
int n, maxdp = minn;
int a[maxn] = {0}, dp[maxn] = {0};

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1] = a[1];
	for(int i = 2; i <= n; i++){
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		maxdp = max(maxdp, dp[i]);
	}
	cout << maxdp;
	return 0;
}

