// Problem:  Luogu P2615 [NOIP 2015 提高组] 神奇的幻方
// Link:     https://www.luogu.com.cn/problem/P2615
// Author:   nine19een
// Date:     2025-07-12

#include<bits/stdc++.h>
using namespace std;
int n, N, ti = 0, tj = 0;
int a[50][50];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	for(int i = 1; i <= 50; i++){
		for(int j = 1; j <= 50; j++){
			a[i][j] = 0;
		}
	}
	cin >> n;
	N = n * n;
	for(int i = 1; i <= N; i++){
		if(i == 1){
			a[1][n/2 + 1] = 1;
			ti = i;
			tj = n/2 + 1;
			continue;
		}
		if(ti == 1 && tj != n){
			a[n][tj + 1] = i;
			ti = n;
			tj += 1;
			continue;
		}
		if(tj == n && ti != 1){
			a[ti - 1][1] = i;
			ti -= 1;
			tj = 1;
			continue;
		}
		if(ti == 1 && tj == n){
			a[ti + 1][tj] = i;
			ti += 1;
			continue;
		}
		if(ti != 1 && tj != n){
			if(a[ti - 1][tj + 1] == 0){
				a[ti - 1][tj + 1] = i;
				ti -= 1;
				tj += 1;
				continue;
			}
			else if(a[ti - 1][tj + 1] != 0){
				a[ti + 1][tj] = i;
				ti += 1;
				continue;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << a[i][n]<< endl;
	}
	return 0;
}

