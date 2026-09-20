// Problem:  Luogu P9974 [USACO23DEC] Candy Cane Feast B
// Link:     https://www.luogu.com.cn/problem/P9974
// Author:   nine19een
// Date:     2025-07-12

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;
long long cow[maxn] = {0}, candy[maxn] = {0};
int N, M;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> N >> M;
	for(int j = 1; j <= N; j++){
		cin >> cow[j];
	}
	for(int i = 1; i <= M; i++){
		cin >> candy[i];
	}
	for(int i = 1; i <= M; i++){
		long long high = 0;
		for(int j = 1; j <= N; j++){
			if(cow[j] > high && cow[j] <= candy[i]){
				long long moo = cow[j]; 
				cow[j] += cow[j] - high;
				high = moo;
				continue;
			}
			if(cow[j] > candy[i]){
				cow[j] += candy[i] - high;
				break;
			}
		}
	}
	for(int j = 1; j <= N; j++){
		cout << cow[j] << endl;
	}	
	return 0;
}
