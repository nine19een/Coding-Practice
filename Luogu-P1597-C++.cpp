// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1597
// Author:   nine19een
// Date:     2025-07-07

#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0, c = 0;
char str[1005];
int main()
{
	cin.getline(str,1005);
	int len = strlen(str);
	for(int i =0; i < len - 3; i++)
	{
		
		if(str[i] == 'a' && str[i+1] == ':' && str[i+2] == '=')
			{
				if(str[i+3] <= 57 && str[i+3] >= 48)
					a = str[i+3] - 48;
				else if(str[i+3] == 97)
					a = a;
				else if(str[i+3] == 98)
					a = b;
				else if(str[i+3] == 99)
					a = c;
				i += 4;
			}
			
				
		else if(str[i] == 'b' && str[i+1] == ':' && str[i+2] == '=')
		{
			if(str[i+3] <= 57 && str[i+3] >= 48)
				b = str[i+3] - 48;
			else if(str[i+3] == 97)
				b = a;
			else if(str[i+3] == 98)
				b = b;
			else if(str[i+3] == 99)
				b = c;
			i += 4;						
		}

		else if(str[i] == 'c' && str[i+1] == ':' && str[i+2] == '=')
		{
			if(str[i+3] <= 57 && str[i+3] >= 48)
				c = str[i+3] - 48;
			else if(str[i+3] == 97)
				c = a;
			else if(str[i+3] == 98)
				c = b;
			else if(str[i+3] == 99)
				c = c;
			i += 4;			
		}

	}
	cout << a << " " << b << " " << c;
	return 0;
}
