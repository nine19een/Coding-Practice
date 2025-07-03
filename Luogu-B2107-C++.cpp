// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/B2107
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
	for( int j = 1 ; j <= m ; j++)
	{
		for( int i = n ; i >= 1 ; i--)
		{
			cout << a[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}
