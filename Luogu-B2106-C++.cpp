// Problem:  Luogu B2106 矩阵转置
// Link:     https://www.luogu.com.cn/problem/B2106
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];
int main()
{
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++)
	{
		for( int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
		}
	}
	for( int i = 1 ; i <= m ; i++)
	{
		for( int j = 1 ; j <= n ; j++)
		{
			cout << a[j][i] << " " ;
		}
		cout << endl;
	}
	return 0;
}
