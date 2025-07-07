// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2842
// Author:   nine19een
// Date:     2025-07-08

#include <bits/stdc++.h>
using namespace std;
int n, w;
const int inf = 1e9;
int a[10005], f[10005];
int money(int p[10005], int q[10005], int c, int b)
{
	p[0] = 0;
	for(int i = 1; i <= c; i++)
	{
		if(q[0]>i)
			p[i] = inf;
		else
			for(int j = 0; j < b; j++)
				if(q[j] <= i)
					p[i] = min(p[i], p[i-q[j]] + 1); 
	}
	return p[c];
}

int main()
{
	for(int i = 0; i < 10005; i++)
	{
		a[i] = 0;
		f[i] = inf;
	}	
	cin >> n >> w;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << money(f, a, w, n);
	return 0;
}
