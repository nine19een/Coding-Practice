// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P5728
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int N;
int a[1005][1005];
int main()
{
	cin >> N;
	int n = 0;
	for( int i = 1 ; i <= N ; i++)
	{
		for( int j = 1 ; j <= 3 ; j++)
		{
			cin >> a[i][j];
		}
	}
	for( int i = 1 ; i <= N - 1 ; i++)
	{
		for( int j = i + 1 ; j <= N ; j++)
		{
			if(	(abs(a[j][1]-a[i][1])<=5 && abs(a[j][2]-a[i][2])<=5 && abs(a[j][3]-a[i][3])<=5) 
			&& abs((a[j][1] + a[j][2] + a[j][3])-(a[i][1] + a[i][2] + a[i][3])) <= 10)
				n++;
		}
	}
	cout << n;
	return 0;
}
