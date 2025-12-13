// Problem:  Luogu P1876 开灯
// Link:     https://www.luogu.com.cn/problem/P1876
// Author:   nine19een
// Date:     2025-12-13

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n;
	cin >> n;
	for(int i = 1; i <= n / i; ++i){
		cout << i * i << " ";
	}
	return 0;
}
