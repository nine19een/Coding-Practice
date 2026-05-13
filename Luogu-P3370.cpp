// Problem:  Luogu P3370 【模板】字符串哈希
// Link:     https://www.luogu.com.cn/problem/P3370
// Author:   nine19een
// Date:     2025-08-19

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll maxn = 1e9 + 7;

int N;
string str;
vector<string>a[20015];

void HASH(){
	ll hash = 0;
	for(int p : str){
		hash = (hash * 131 + p) % maxn;
	}
	hash %= 20011;
	a[hash].push_back(str);
}

int Examine(){
	int ans = 0;
	for(int i = 0; i <= 20011; i++){
		if(a[i].empty()){
			continue;
		}
		else if(a[i].size() == 1){
			ans++;
		}
		else{
			sort(a[i].begin(), a[i].end());
			auto end = unique(a[i].begin(), a[i].end());
			ans += distance(a[i].begin(), end);
		}
	}
	return ans;
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; ++i){ 
		cin >> str;
		HASH();
	}
	cout << Examine();
	return 0;
}
