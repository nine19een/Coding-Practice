// Problem:  Luogu P5731 【深基5.习6】蛇形方阵
// Link:     https://www.luogu.com.cn/problem/P5731
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int tot=1,n;
int a[105][105];
int main ()
{
	cin >> n;
	int x=1 , y=1;
	a[1][1]=tot++;
	while(tot <= n*n)
	{
		while(y+1 <= n && a[x][y+1] == 0)
			a[x][++y] = tot++;
		while(x+1 <= n && a[x+1][y] == 0)
			a[++x][y] = tot++;
		while(y-1 >= 1 && a[x][y-1] == 0)
			a[x][--y] = tot++;
		while(x-1 >= 1 && a[x-1][y] == 0)
			a[--x][y] = tot++;
	}
	for( int i = 1 ; i <= n ; i++)
	{
		for( int j = 1 ; j <= n ; j++)
		{
			printf("%3d" , a[i][j]);
		}
		cout << endl;
	}
	return 0;
}
