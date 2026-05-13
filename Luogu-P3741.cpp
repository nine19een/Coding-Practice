// Problem:  Luogu P3741 小果的键盘
// Link:     https://www.luogu.com.cn/problem/P3741
// Author:   nine19een
// Date:     2025-07-08

#include <bits/stdc++.h>
using namespace std;
int n,count1 = 0, count2 = 0; 
char s[105];
int main()
{
	memset(s, '0', sizeof(s));
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 'V' && s[i+1] == 'K')
		{
			count1++;
			i++;			
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int count_2 = 0;
		if(s[i] == 'K')
		{
			s[i] = 'V';
			for(int j = 1; j <= n; j++)
			{
				if(s[j] == 'V' && s[j+1] == 'K')
				{	
					count_2++;
					j++;					
				}
			}
			s[i] = 'K';		
		if(count_2 >= count2)
			count2 = count_2 ;	
		}
			
		else
		{
			s[i] = 'K';	
			for(int j = 1; j <= n; j++)
			{
				if(s[j] == 'V' && s[j+1] == 'K')
				{	
					count_2++;
					j++;					
				}
			}
			s[i] = 'V';		
		if(count_2 >= count2)
			count2 = count_2 ;			
		}	
		}
	cout << max(count1, count2);
	return 0;
}
