// Problem:  Codeforces Round 1059 B. Beautiful String
// Link:     https://codeforces.com/contest/2162/problem/B
// Author:   nine19een
// Date:     2025-10-17

#include<bits/stdc++.h>
using namespace std;

int t;

void op(){
	int n;
	string s, ans;
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			ans.push_back(i + 1);
		}
	}
	int size = ans.size();
	if(size == 0){
		cout << 0 << "\n\n";
		return;
	}
	else{
		cout << size << '\n';
		for(int c : ans){
			cout << c << " ";
		}
		cout << '\n';
		return;
	}
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
