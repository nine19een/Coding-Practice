// Problem:  Luogu P1125 [NOIP 2008 提高组] 笨小猴
// Link:     https://www.luogu.com.cn/problem/P1125
// Author:   nine19een
// Date:     2025-07-09

#include<bits/stdc++.h>
using namespace std;
char word[105];
int letter[30];
bool check(int num)
{
	if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19 || num == 23 || num == 29 || num == 31 || num == 37 || num == 41 || num == 43 || num == 47 || num == 53 || num == 59 || num == 61 || num == 67 || num == 71 || num == 73 || num == 79 || num == 83 || num == 89 || num == 97)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	memset(word, '\0', 105);
	memset(letter, '\0', 30);
	cin >> word;
	int len = strlen(word);
	int maxn = 0, minn = len;
	for(int i = 0; i < len; i++)
	{
		letter[word[i]]++;
	}
	for(int i = 'a'; i <= 'z'; i++)
	{
		if(letter[i] != 0)
		{
			if(letter[i]>= maxn)
			{
				maxn = letter[i];	
			}
			if(letter[i] <= minn)
			{
				minn = letter[i];
			}				
		}
		else
		{
			continue;
		}
	}
	if(check(maxn - minn))
	{
		cout << "Lucky Word" << endl << maxn - minn;
	}
	else if(!check(maxn - minn))
	{
		cout << "No Answer" << endl << "0";	
	}
	return 0;
}
