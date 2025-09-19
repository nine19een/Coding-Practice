// Problem:  Luogu P5733 【深基6.例1】自动修正
// Link:     https://www.luogu.com.cn/problem/P5733
// Author:   nine19een
// Date:     2025-07-04

#include<bits/stdc++.h>
using namespace std;
string str;
char c;
int main()
{
	cin >> str;
	for( int i = 0 ; i < str.length() ; i++)
		if( str[i] < 123 && str[i] > 96) 
		{
			c = str[i] - 32;
			cout << c;
		}
		else
			cout << str[i];	
		return 0;
}
