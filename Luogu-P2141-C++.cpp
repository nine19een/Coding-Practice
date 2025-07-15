// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2141
// Author:   nine19een
// Date:     2025-07-16

#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
int const maxn = 1e4;
int a[105];
vector<int>sum;
bool repeat[105];
int main(){
	sum.reserve(maxn);
	memset(a, 0, sizeof(a));
	memset(repeat, 0, sizeof(repeat));
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n-1; i++){
		for(int j = i + 1; j <= n; j++){
			sum.push_back(a[i] + a[j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int p : sum){
			if(p == a[i] && !repeat[i]){
				cnt++;
				repeat[i] = true;
			}
		}
	}
	cout << cnt;
	return 0;
}
