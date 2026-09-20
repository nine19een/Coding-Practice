// Problem:  Codeforces Round 1057 A. Circle of Apple Trees
// Link:     https://codeforces.com/contest/2153/problem/A
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;

int t;

void op(){
	int n, cnt = 0;
	cin >> n;
	vector<int>cnt_num(n + 5, 0);
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		cnt_num[num]++;
	}
	for(int i = 1; i <= n; ++i){
		cnt += (cnt_num[i] == 0) ? 0 : 1;
	}
	cout << cnt << '\n';
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