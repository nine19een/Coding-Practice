// Problem:  Codeforces Round 1057 B. Bitwise Reversion
// Link:     https://codeforces.com/contest/2153/problem/B
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;
int const maxn = 35;

int t;

bool isEven(int num){
	return !(num & 1);
}

void CNT(int num, int cnt_num[]){
	for(int i = 0; i < maxn; ++i){
		cnt_num[i] += (num & 1) ? 1 : 0;
		num = num >> 1;
		if(!(num & -num)){
			break;
		}
	}
}

void op(){
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int cnt_num[maxn];
	memset(cnt_num, 0, sizeof(cnt_num));
	CNT(X, cnt_num);
	CNT(Y, cnt_num);
	CNT(Z, cnt_num);
	for(int i = 0; i < maxn; ++i){
		if(cnt_num[i] != 0 && isEven(cnt_num[i])){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		op();
	}
	return 0;
}