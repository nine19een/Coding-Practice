// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1031
// Author:   nine19een
// Date:     2025-07-10

#include<bits/stdc++.h>
using namespace std;
int N, m, cnt = 0;
int n[105];
int main()
{
	cin >> N;
	int sum_ = 0;
	for(int i = 1; i <= N; i++)
	{
		cin >> n[i];
		sum_ += n[i];
	}
	int avr = sum_ / N;
	m = N - 1;
	for(int i = 1; i <= N; i++)
	{
		if(n[i] < avr)
		{
			n[i+1] -= avr - n[i];
			cnt ++;                                                       
		}
		else if(n[i] > avr)
		{
			n[i+1] += n[i] - avr;
			cnt ++;
		}
		else if(n[i] == avr)
		{
			continue;
		}
	}
	cout << cnt;
	return 0;
}
