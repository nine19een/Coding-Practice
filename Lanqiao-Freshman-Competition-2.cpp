// Problem:  【蓝桥新生编程排位赛】 加工等级之和
// Link:     https://www.lanqiao.cn/problems/21026/learning/?contest_id=262
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e5 + 5, maxm = 1e4 + 5;
int cnt_num[maxn], n;
ll ans, a[maxm];

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		cnt_num[a[i]]++;
	}
	for(int i = 1; i <= n; ++i){
		if(!cnt_num[a[i] - 1]){
			ans += a[i];
		}
	}
	cout << ans;
	return 0;
}
