// Problem:  Luogu P1914 小书童——凯撒密码
// Link:     https://www.luogu.com.cn/problem/P1914
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int n;
char m;
string str;
int main()
{
	cin >> n;
	cin >> str;
	for( int i = 0 ; i < str.length() ; i++)
	{
		m = str[i] ;
		if( m + n <= 122)
			cout << char ( m + n );
		else
			cout << char ( m + n - 26);
	}
	return 0;
}
