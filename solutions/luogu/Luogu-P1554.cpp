// Problem:  Luogu P1554 梦中的统计
// Link:     https://www.luogu.com.cn/problem/P1554
// Author:   nine19een
// Date:     2025-07-04

#include<bits/stdc++.h>
using namespace std;
int M,N;
int t[10]; 
void statistic( int n , int (&t)[10])
{
	while( n > 0 )
	{
		t[n%10]++ ;
		n /= 10 ; 
	}
}
int a[1000005];
int main()
{
	cin >> M >> N;
	for( int i = 1 ; i <= N - M + 1 ; i++)
	{
		a[i] = M + i - 1;
		statistic( a[i] , t );
	}
	for( int i = 0 ; i < 10 ; i++)
		cout << t[i] << " ";
	return 0;
}
