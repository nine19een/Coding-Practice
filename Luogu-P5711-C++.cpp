// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P5711
// Author:   nine19een
// Date:     2025-07-02

#include<bits/stdc++.h>
using namespace std;
int main () {
	int year;
	cin >> year;
	if (( year % 100 != 0 && year % 4 == 0 ) || ( year % 400 == 0)){
		cout << "1";
	}else {
		cout << "0";
	}
	return 0;
}
