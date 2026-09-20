// Problem:  Luogu P12156 [蓝桥杯 2025 省 Java B] 电池分组
// Link:     https://www.luogu.com.cn/problem/P12156
// Author:   nine19een
// Date:     2025-09-09

#include<bits/stdc++.h>
using namespace std;

int T;

void howMany1(int x, int cnt[]){
	int i = 1;
	while(x != 0){
		if(x & 1){
			cnt[i]++;
		}
		i++;
		x = x >> 1;
	}
}

bool isODD(int x){
	return x & 1;
}

void Test(){
	int n, cnt[20];
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		howMany1(num, cnt);
	}
	for(int i = 1; i <= 18; ++i){
		if(isODD(cnt[i])){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	cin >> T;
	while(T--){
		Test();
	}
	return 0;
}
