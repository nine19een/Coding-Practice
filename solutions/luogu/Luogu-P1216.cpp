// Problem:  Luogu P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
// Link:     https://www.luogu.com.cn/problem/P1216
// Author:   nine19een
// Date:     2025-07-07

#include <bits/stdc++.h>
using namespace std;
int r, f_max = 0;
int a[1005][1005], f[1005][1005];
int main()
{
	cin >> r;
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= i; j++)
			cin >> a[i][j];
	}
	if(r == 1)
		f_max = a[1][1];
	else
	{
		f[1][1] = a[1][1];
		for(int i = 2; i <= r; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				f[i][j] = a[i][j];
				if(j == 1)
					f[i][1] += f[i-1][1];
				else if(j == i)
					f[i][i] += f[i-1][i-1];
				else
				{
					if(f[i-1][j-1] >= f[i-1][j])
						f[i][j] += f[i-1][j-1];
					else
						f[i][j] += f[i-1][j];
				}	
			}
		}
		f_max = f[r][1];
		for(int i = 1; i<r; i++)
		{
			if(f[r][i+1] >= f_max)
				f_max = f[r][i+1];
		}
	}
	cout << f_max;
	return 0;
}
