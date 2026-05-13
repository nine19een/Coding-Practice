// Problem:  Luogu P1428 小鱼比可爱
// Link:     https://www.luogu.com.cn/problem/P1428
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main()
{
	cin >> n;
	int m = 0;
	for( int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	} 
	for( int i = 1 ; i <= n ; i++)
	{
		for( int j = 1 ; j < i ; j++)
		{
			if(a[i] > a[j])	
				m++;
		}
		cout << m << " ";
		m = 0;
	}
	return 0;
} 
