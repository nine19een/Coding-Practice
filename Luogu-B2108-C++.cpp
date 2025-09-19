// Problem:  Luogu B2108 图像模糊处理
// Link:     https://www.luogu.com.cn/problem/B2108
// Author:   nine19een
// Date:     2025-07-16

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;
int n, m;
double a[maxn][maxn], b[maxn][maxn];
void dim(double a[][maxn], double &A, double &b, int i, int j){
	b = round((A + a[i-1][j] + a[i][j+1] + a[i+1][j] + a[i][j-1]) / 5);
	return;
}
int main(){
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i != 1 && i != n && j != 1 && j != m){
				dim(a, a[i][j], b[i][j], i, j);
			}
			else{
				b[i][j] = a[i][j];
			}		
		}		
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << b[i][j] << " ";		
		}
		cout << endl;		
	}
	return 0;
}
