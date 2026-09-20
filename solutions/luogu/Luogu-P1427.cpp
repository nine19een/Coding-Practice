// Problem:  Luogu P1427 小鱼的数字游戏
// Link:     https://www.luogu.com.cn/problem/P1427
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int n,c=0;
int a[105];
int main()
{
	while( cin >> n)
	{
		if( n == 0)
			break;
		c++;
		a[c] = n;
	}
	for( int i = c ; i >= 1 ; i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}
