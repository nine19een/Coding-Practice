// Problem:  Luogu B2050 三角形判断
// Link:     https://www.luogu.com.cn/problem/B2050
// Author:   nine19een
// Date:     2025-10-21

#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
	cin >> a >> b >> c;
	if(a + b > c && b + c > a && a + c > b){
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
