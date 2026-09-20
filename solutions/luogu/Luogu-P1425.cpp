// Problem:  Luogu P1425 小鱼的游泳时间
// Link:     https://www.luogu.com.cn/problem/P1425
// Author:   nine19een
// Date:     2025-07-02

#include<bits/stdc++.h>
using namespace std;
int main () {
	int a;
	int b;
	int c;
	int d;
	cin >> a >> b >> c >> d;
	if ( d >= b ){
		cout << c - a << " " << d - b;
	} else{
		cout << c - a - 1 << " " << d + 60 - b;
	}
	return 0;
}
