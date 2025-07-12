// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1699
// Author:   nine19een
// Date:     2025-07-12

#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int bi, bj, ri, rj, li, lj, ans;
int main(){
	freopen("bucket.in","r",stdin);
	freopen("bucket.out","w",stdout);
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			cin >> a[i][j];
			if(a[i][j] == 'B'){
				bi = i;
				bj = j;
			}
			if(a[i][j] == 'R'){
				ri = i;
				rj = j;
			}
			if(a[i][j] == 'L'){
				li = i;
				lj = j;
			}			
		}
	}
	if(bi != li && bj != lj){
		ans = (abs(bi-li) + abs(bj-lj) - 1);
	}
	if(bi == li){
		if(ri == bi && ((rj < lj && rj > bj) || (rj > lj && rj < bj))){
			ans = abs(bj-lj) + 1;
		}
		else{
			ans = abs(bj-lj) - 1;
		}
	}
	if(bj == lj){
		if(rj == bj && ((ri < li && ri > bi) || (ri > li && ri < bi))){
			ans = abs(bi-li) + 1;
		}
		else{
			ans = abs(bi-li) - 1;
		}
	}
	cout << ans;
	return 0;
}

