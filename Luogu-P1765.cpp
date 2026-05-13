// Problem:  Luogu P1765 手机
// Link:     https://www.luogu.com.cn/problem/P1765
// Author:   nine19een
// Date:     2025-07-07

#include <bits/stdc++.h>
using namespace std;
int count_ = 0;
char a[1005];
int main()
{
	cin.getline(a,1005);
	for(int i = 0; i < 1005; i++)
	{
		if(a[i] == 'a' || a[i] == 'd' || a[i] == 'g' || a[i] == 'j' || a[i] == 'm' || a[i] == 'p' || a[i] == 't' || a[i] == 'w' || a[i] == ' ' )
			count_ += 1;
		else if(a[i] == 'b' || a[i] == 'e' || a[i] == 'h' || a[i] == 'k' || a[i] == 'n' || a[i] == 'q' || a[i] == 'u' || a[i] == 'x')
			count_ += 2;
		else if(a[i] == 'c' || a[i] == 'f' || a[i] == 'i' || a[i] == 'l' || a[i] == 'o' || a[i] == 'r' || a[i] == 'v' || a[i] == 'y')
			count_ += 3;
		else if(a[i] == 's' || a[i] == 'z')
			count_ += 4;
	}
	cout << count_;
	return 0;
}
