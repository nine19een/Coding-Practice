// Problem:  【蓝桥新生编程排位赛】 机器人的行动轨迹
// Link:     https://www.lanqiao.cn/problems/21029/learning/?contest_id=262
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, ans;

int main(){
	cin >> n;
	ans = (n <= 3) ? n : (n - 3) * 5 + 3;
	cout << ans;
	return 0;
}
