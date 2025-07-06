// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/B3637
// Author:   nine19een
// Date:     2025-07-06

#include<bits/stdc++.h>
using namespace std;
int findMax(int a[], int n) 
{
	int m;
	m = a[1];
	for(int i = 1; i < n; i++)
	{
		if(a[i+1] > m )
			m = a[i+1];
	}
	return m;
}

int n;
int a[1000005], f[1000005];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		int f_max = 0;
		for(int j = 1 ;j < i; j++)
		{
			if(a[j] < a[i] && f[j] >= f_max)
				f_max = f[j];
		}
		f[i] = f_max + 1;
	}
	cout << findMax(f, n);
	return 0;
}
