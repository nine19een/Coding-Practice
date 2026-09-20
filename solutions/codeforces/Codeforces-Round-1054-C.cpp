// Problem:  Codeforces Round 1054 C. MEX rose
// Link:     https://codeforces.com/contest/2149/problem/C
// Author:   nine19een
// Date:     2025-10-03

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e5 + 5;

int t, a[maxn], cnt_num[maxn];

void op(){
	int n, k, cnt_k = 0, cnt_empty = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		cnt_k += (a[i] == k) ? 1 : 0;
		cnt_num[a[i]]++;
	}
	for(int i = 0; i < k; ++i){
		cnt_empty += (cnt_num[i]) ? 0 : 1;
	}
	if(cnt_k >= cnt_empty){
		cout << cnt_k << "\n";
	}
	else{
		cout << cnt_empty << "\n";
	}
	memset(a, 0, sizeof(a));
	memset(cnt_num, 0, sizeof(cnt_num));
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
