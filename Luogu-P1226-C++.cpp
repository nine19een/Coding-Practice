// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1226
// Author:   nine19een
// Date:     2025-07-11

#include <bits/stdc++.h>
using namespace std;
long long A, B, P;
long long solve(long long a, long long b, long long p)
{
	if(a == 0)
	{
		return 0;
	}
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % p;
	}
	long long r = b % 2;
	if(r == 0)
	{
		long long zyc = solve(a, b/2, p);
		return (zyc * zyc) % p;
	}
	else if(r == 1)
	{
		return (a * solve(a, b-1, p)) % p;
	}
}
int main()
{
	cin >> A >> B >> P;
	cout << A << "^" << B << " mod " << P << "=" <<solve(A, B, P);
	return 0;
}
