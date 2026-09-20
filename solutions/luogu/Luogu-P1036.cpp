// Problem:  Luogu P1036 [NOIP 2002 普及组] 选数
// Link:     https://www.luogu.com.cn/problem/P1036
// Author:   nine19een
// Date:     2025-07-17

#include<bits/stdc++.h>
using namespace std;
int n, k;
int num[25];
int const maxn = 1e6;
vector<int>path;
int cnt = 0;
bool isPrimeNumber(int PrimeNumber){
	for(int i = 2; i < PrimeNumber; i++){
		if(PrimeNumber % i == 0){
			return false;
		}
	}	
	return true;
}
void solve(int start){
	for(int i = start; i < n; i++){

		path.push_back(num[i]);
		if(path.size() == k){
			int sum = 0;
			for(int p : path){
				sum += p;
			}
			if(isPrimeNumber(sum)){
				cnt++;
			}
			path.pop_back();
			continue;
		}
		solve(i + 1);			
	}
	path.pop_back();
	return;
}

int main(){
	path.reserve(25);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	sort(num, num + n);
	solve(0);
	cout << cnt;
	return 0;
}
