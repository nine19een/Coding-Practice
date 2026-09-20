// Problem:  Luogu P1321 单词覆盖还原
// Link:     https://www.luogu.com.cn/problem/P1321
// Author:   nine19een
// Date:     2025-07-04

#include<bits/stdc++.h>
using namespace std;
string str;
int boy = 0 , girl = 0;
int main()
{
	cin >> str;
	for( int i = 0 ; i < str.length() ; i++)
	{
		if(str[i] == 'b' && str[i+1] == 'o' && str[i+2] == 'y')
		{
			boy++;
			i += 2;
		}
		else if((str[i] == 'b' && str[i+1] == 'o' && str[i+2] != 'y') || (str[i] == 'o' && str[i+1] == 'y'))
		{
			boy++;
			i += 1;
		}
		else if((str[i] == 'b' && str[i+1] != 'o') ||(str[i] == 'o' && str[i+1] != 'y') ||str[i] == 'y')
		{
			boy++;
		}
		else if(str[i] == 'g' && str[i+1] == 'i' && str[i+2] == 'r' && str[i+3] == 'l')	
		{
			girl++;
			i += 3;
		}			
		else if((str[i] == 'g' && str[i+1] == 'i' && str[i+2] == 'r' && str[i+3] != 'l') || (str[i] == 'i' && str[i+1] == 'r' && str[i+2] == 'l'))
		{
			girl++;
			i += 2;
		}	
		else if((str[i] == 'g' && str[i+1] == 'i' && str[i+2] != 'r') || (str[i] == 'i' && str[i+1] == 'r' && str[i+2] != 'l') || (str[i] == 'r' && str[i+1] == 'l'))
		{
			girl++;
			i += 1;
		}		
		else if((str[i] == 'g' && str[i+1] != 'i') ||(str[i] == 'i' && str[i+1] != 'r') || (str[i] == 'r' && str[i+1] != 'l') || str[i] == 'l')
		{
			girl++;
		}	
	}
	cout << boy << "\n" << girl;
}
