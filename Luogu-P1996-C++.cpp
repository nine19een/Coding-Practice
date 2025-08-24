// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1996
// Author:   nine19een
// Date:     2025-08-24

#include<bits/stdc++.h>
using namespace std;

list<int>l;
int n, m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		l.push_back(i);
	}
	auto it = l.begin(); end = l.end();
	while(!l.empty()){
		for(int i = 1; i < m; ++i){
			++it;
			if(it == end){
				it = l.begin();
			}
		}
		cout << *it << " ";
		it = l.erase(it);
		if(it == end){
			it = l.begin();
		}
	}
	return 0;
}
