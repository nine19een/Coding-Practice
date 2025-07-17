// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P4924
// Author:   nine19een
// Date:     2025-07-18

#include<bits/stdc++.h>
using namespace std;

int n, m;
int const maxn = 505;
int a[maxn][maxn], x[maxn] = {0}, y[maxn] = {0}, r[maxn] = {0}, z[maxn] = {0};

void magic(int x, int y, int r, int z){
	int store[maxn][maxn];
	memset(store, 0, sizeof(store));
	int X = x + r, Y = y + r;
	int I = 1, J = 1;
	for(int i = x - r; i <= X; i++){
		for(int j = y - r; j <= Y; j++){
			store[I][J] = a[i][j];
			J++;
		}
		J = 1;
		I++;
	}
	if(z == 0){
		I = 2 * r + 1;
		J = 1;
		for(int i = x - r; i <= X; i++){
			for(int j = y - r; j <= Y; j++){
				a[i][j] = store[I][J];
				I--;
			}
			J++;
			I = 2 * r + 1;
		}
	}
	else if(z == 1){
		I = 1;
		J = 2 * r + 1;
		for(int i = x - r; i <= X; i++){
			for(int j = y - r; j <= Y; j++){
				a[i][j] = store[I][J];
				I++;
			}
			J--;
			I = 1;
		}
	}
	return;
}

int main(){
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> x[i] >> y[i] >> r[i] >> z[i]; 
	}
	int bili = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = bili;
			bili++;
		}
	}
	for(int i = 1; i <= m; i++){
		magic(x[i], y[i], r[i], z[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}	
	return 0;
}
