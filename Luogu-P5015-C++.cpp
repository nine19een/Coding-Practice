// Problem:  Luogu P5015 [NOIP 2018 普及组] 标题统计
// Link:     https://www.luogu.com.cn/problem/P5015
// Author:   nine19een
// Date:     2025-07-04

#include<bits/stdc++.h>
using namespace std;
string str;
int t = 0;
int main()
{
	getline( cin , str);
	for( int i = 0 ; i <str.length() ; i++)
	{
		if( str[i] != 32 && str[i] != 10 )
			t++;
	}
	cout << t;
	return 0;
}
