// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1055
// Author:   nine19een
// Date:     2025-07-13

#include<bits/stdc++.h>
using namespace std;
int X,rem;
int num[10];
string str;
char c[20];
int main()
{
	cin >> str;
	int x = 1;
	for( int i = 0 ; i < str.length() ; i++ )
	{
		if(isdigit(str[i]))
		{
			c[x] = str[i];
			x++;
		}
	}
	for( int i = 1 ; i <= 9 ; i++)
	{
		num[i] = c[i] - '0';
	for( int i = 1 ; i <= 9 ; i++ )
		X += num[i] * i;
	rem = X % 11;
	if( str[12] == 'X' && rem == 10 )
		cout << "Right";
	else if( (str[12] - '0' ) == rem )
		cout << "Right";
	else
	{
		for( int i = 0 ; i < 12 ; i++)
			cout << str[i];
		cout << rem;
	}
	return 0;
}
