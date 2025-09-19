// Problem:  Luogu P1200 [USACO1.1] 你的飞碟在这儿 Your Ride Is Here
// Link:     https://www.luogu.com.cn/problem/P1200
// Author:   nine19een
// Date:     2025-07-07

#include <bits/stdc++.h>
using namespace std;
char group[10], comet[10];
long long count_c = 1, count_g = 1;
int main()
{
	cin >> comet >> group;
	int len_c = strlen(comet);
	int len_g = strlen(group);
	for(int i = 0; i < len_c; i++)
	{
		if(i == 0)	
			count_c	= comet[i] - 64;
		else
			count_c *= comet[i] - 64;
	}
	for(int i = 0; i < len_g; i++)
	{
		if(i == 0)	
			count_g	= group[i] - 64;
		else
			count_g *= group[i] - 64;
	}
	if(count_c % 47 == count_g % 47)	
		cout << "GO";
	else 
		cout << "STAY";
	return 0;
}
