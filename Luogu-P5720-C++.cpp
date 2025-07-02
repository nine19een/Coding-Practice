// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P5720
// Author:   nine19een
// Date:     2025-07-02

#include<bits/stdc++.h>
using namespace std;
int a , n;
int main(){
	cin >> a;
	int n = 0;
	for( a ; a >= 1 ; n++){
		a = a / 2;
	}
	cout << n;
	return 0;
}
