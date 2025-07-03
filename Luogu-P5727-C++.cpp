// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P5727
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,m;
	cin >> n;
	m = n;
	int t = 1;
	while(n != 1)
	{
		if( n%2 == 1)
			n = n*3+1;
		else
			n = n/2;
		a[t] = n;		
		t++;
	}
	for( int j = t - 1 ; j >= 1 ; j--)
	{
		cout << a[j] << " " ;
	}
	cout << m;
	return 0;
}
