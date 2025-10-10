// Problem:  【蓝桥新生编程排位赛】 对角线上的最值
// Link:     https://www.lanqiao.cn/problems/21025/learning/?contest_id=262
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

int n, a[105][105], ans_max = 0, ans_min = 1e5;

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		ans_max = max(a[i][i], ans_max);
		ans_max = max(a[i][n - i + 1], ans_max);
		ans_min = min(a[i][i], ans_min);
		ans_min = min(a[i][n - i + 1], ans_min);
	}
	cout << ans_max << " " << ans_min;
	return 0;
}
