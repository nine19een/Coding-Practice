// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P12162
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int cnt;

void isFive(int num){
	int sum = 0, r;
	for(int i = 1; i <= 7; ++i){
		r = num % 10;
		sum += r;
		if(num < 10){
			break;
		}
		num = (num - r) / 10;
	}
	if(sum % 5 == 0){
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	for(int i = 1; i <= 202504; ++i){
		isFive(i);
	}
	cout << cnt;
	return 0;
}
