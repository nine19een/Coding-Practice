// Problem:  Luogu B2105 矩阵乘法
// Link:     https://www.luogu.com.cn/problem/B2105
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105][105],b[105][105],c[105][105]; 
int main()
{
	cin >> n >> m >> k;
	for( int i = 1 ; i <= n ; i++)
	{
		for( int j = 1; j <= m ;j++)
		{
			cin >> a[i][j];
		}
	}
	for( int i = 1 ; i <= m ; i++)
	{
		for( int j = 1; j <= k ;j++)
		{
			cin >> b[i][j];
		}
	}
	for( int i = 1 ; i <= n ; i++)
	{
		for( int j = 1; j <= k ; j++)
		{
			for( int x = 1 ; x <= m ; x++)
			{
				c[i][j] += a[i][x]*b[x][j];
			}
		}
	}
	for( int i = 1 ; i <= n ; i++)
	{
		for ( int j = 1 ; j <= k ; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	} 
	return 0;
} 
