// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1048
// Author:   nine19een
// Date:     2025-07-21

#include<bits/stdc++.h>
using namespace std;
int T, M;
int value[105], Time[105];

void solve(){
	int f[1005];
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= M; i++){
		for(int restime = T; restime >= Time[i]; restime--){
			f[restime] = max(f[restime], f[restime - Time[i]] + value[i]);
		}
	}
	cout << f[T];
	return;
}

int main(){
	memset(value, 0, sizeof(value));
	memset(Time, 0, sizeof(Time));	
	cin >> T >> M;
	for(int i = 1; i <= M; i++){
		cin >> Time[i] >> value[i] ;
	}
	solve();
	return 0;
} 
