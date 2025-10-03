// Problem:  Codeforces Round 1054 A. Be Positive
// Link:     https://codeforces.com/contest/2149/problem/A
// Author:   nine19een
// Date:     2025-10-03

#include<bits/stdc++.h>
using namespace std;

int t;

bool isEven(int x){
	return !(x & 1);
}

void op(){
	int n, cnt = 0, cnt_minus1 = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		if(num == 0){
			cnt++;
		}
		else if(num == -1){
			cnt_minus1++;
		}
	}
	cnt += (isEven(cnt_minus1)) ? 0 : 2;
	cout << cnt << "\n";
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
