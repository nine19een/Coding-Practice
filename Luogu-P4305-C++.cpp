// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P4305
// Author:   nine19een
// Date:     2025-08-19

#include<bits/stdc++.h>
using namespace std;

int const maxn = 100003, maxm = 5e4 + 5;
int T, n, num; 
long long hash_;
vector<int> a[maxn];

bool Repetition(int num, int hash){
	for(int p : a[hash]){
		if(p == num){
			return true;
		}
	}
	return false;
}

void Unique(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> num;
		hash_ = abs(1ll * (num * 131) % maxn);
		if(Repetition(num, hash_)){
			continue;
		}
		a[hash_].push_back(num);
		cout << num << " ";
	}
	for(auto& p : a){
		p.clear();
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		Unique();
	}
	return 0;
}
