// Problem:  Luogu P3912 素数个数
// Link:     https://www.luogu.com.cn/problem/P3912
// Author:   nine19een
// Date:     2025-12-05

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000005, MAXP = 6000000;

int cnt, n;
bool not_prime[MAXN];
vector<int> primes;

int main(){
	primes.reserve(MAXP);
	cin >> n;
	for(int i = 2; i <= n; ++i){
		if(!not_prime[i]){
			primes.push_back(i);
			cnt++;
		}
		for(int p: primes){
			if(p * i > n){
				break;
			}
			not_prime[p * i] = true;
			if(i % p == 0){
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
