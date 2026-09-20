// Problem:  Codeforces Round 1017 F. Trulimero Trulicina
// Link:     https://codeforces.com/contest/2094/problem/F
// Author:   nine19een
// Date:     2025-08-10

#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e4 + 5, maxm = 2e5 + 5;
int t;
int n[maxn], m[maxn], k[maxn], num[maxm];

void Solve(int idx){
	cin >> n[idx] >> m[idx] >> k[idx];
	if(m[idx] % k[idx] != 0){
		int num = 1;
		for(int i = 1; i <= n[idx]; i++){
			for(int j = 1; j <= m[idx]; j++){
				cout << num << " ";
				if(num == k[idx]){
					num = 1;
				}
				else{
					num++;	
				}
			}
			cout << endl;
		}
	}
	else{
		int num = 1, start = 1;
		for(int i = 1; i <= n[idx]; i++){
			for(int j = 1; j <= m[idx]; j++){
				cout << num << " ";
				if(num == k[idx]){
					num = 1;
				}
				else{
					num++;	
				}	
			}
			if(start == k[idx]){
				start = 1;
			}
			else{
				start++;
			}
			num = start;
			cout << endl;
		}		
	}
	return;
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		Solve(i);
		
	}
	
	return 0;
}
