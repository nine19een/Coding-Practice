// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P10424
// Author:   nine19een
// Date:     2025-07-15

#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
int const maxn = 1e7 + 5;
bool Goodnum[maxn];
int main(){
	cin >> n;
	memset(Goodnum, 0, sizeof(Goodnum));
	for(int i = 1; i <= n; i++){
		if(i < 10){
			if(i % 2 == 1){
				Goodnum[i] = true;
			}
		}
		if(i >= 10 && i < 100){
			if(i % 2 == 1 && (i/10) % 2 == 0){
				Goodnum[i] = true;
			}
		}
		if(i >= 100 && i < 1000){
			if((i/1) % 2 == 1 && (i/10) % 2 == 0 && (i/100) % 2 == 1){
				Goodnum[i] = true;
			}
		}
		if(i >= 1000 && i < 10000){
			if((i/1) % 2 == 1 && (i/10) % 2 == 0 && (i/100) % 2 == 1 && (i/1000) % 2 == 0){
				Goodnum[i] = true;
			}
		}	
		if(i >= 10000 && i < 100000){
			if((i/1) % 2 == 1 && (i/10) % 2 == 0 && (i/100) % 2 == 1 && (i/1000) % 2 == 0 && (i/10000) % 2 == 1){
				Goodnum[i] = true;
			}
		}	
		if(i >= 100000 && i < 1000000){
			if((i/1) % 2 == 1 && (i/10) % 2 == 0 && (i/100) % 2 == 1 && (i/1000) % 2 == 0 && (i/10000) % 2 == 1 && (i/100000) % 2 == 0){
				Goodnum[i] = true;
			}
		}
		if(i >= 1000000 && i < 10000000){
			if((i/1) % 2 == 1 && (i/10) % 2 == 0 && (i/100) % 2 == 1 && (i/1000) % 2 == 0 && (i/10000) % 2 == 1 && (i/100000) % 2 == 0 && (i/1000000) % 2 == 1){
				Goodnum[i] = true;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(Goodnum[i] == true){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
