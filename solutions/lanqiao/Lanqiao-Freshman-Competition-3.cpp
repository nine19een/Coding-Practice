// Problem:  【蓝桥新生编程排位赛】 蚀光之刃
// Link:     https://www.lanqiao.cn/problems/21027/learning/?contest_id=262
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(){
	cin >> a >> b >> c >> d;
	if(a == 0){
		cout << d / b;
		return 0;
	}
	if(b == 0){
		cout << c / a;
		return 0;
	}
	cout << min((c / a), (d / b));
	return 0;
}
