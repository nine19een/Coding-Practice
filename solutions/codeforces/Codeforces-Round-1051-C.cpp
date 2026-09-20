// Problem:  Codeforces Round 1051 C. Max Tree
// Link:     https://codeforces.com/contest/2143/problem/C
// Author:   nine19een
// Date:     2025-09-18

#include<bits/stdc++.h>
using namespace std;

struct remain_input{
	int u, v, x, y;
};
int t;

void compare(int i, int u, int v, int x, int y, list<int>& l, unordered_map<int, list<int>::iterator>& um){
	if(i == 1){
		if(x >= y){
			l.push_back(v);
			um[v] = l.begin();
			l.insert(um[v], u);
			um[u] = l.begin();
		}
		else{
			l.push_back(u);
			um[u] = l.begin();
			l.insert(um[u], v);
			um[v] = l.begin();			
		}
	}
	else{
		if(um.count(u)){
			if(x >= y){
				auto it = next(um[u]);
				l.insert(it, v);
				um[v] = prev(it);
			}
			else{
				l.insert(um[u], v);
				um[v] = prev(um[u]);				
			}
		}
		else if(um.count(v)){
			if(x >= y){
				l.insert(um[v], u);
				um[u] = prev(um[v]);	
			}
			else{
				auto it = next(um[v]);
				l.insert(it, u);
				um[u] = prev(it);				
			}			
		}
	}
}

void tree(){
	int n;
	cin >> n;
	list<int> l;
	unordered_map<int, list<int>::iterator> um;
	list<remain_input> remain;
	int u, v, x, y;
	for(int i = 1; i < n; ++i){
		cin >> u >> v >> x >> y;
		if(um.count(u) || um.count(v) || i == 1){
			
			compare(i, u, v, x, y, l, um);
		}
		else{
			remain.push_back({u, v, x, y});
		}
	}
	int cnt_remain = remain.size();
	while(cnt_remain){
		for(auto it = remain.begin(); it != remain.end();){
			if(um.count((*it).u) || um.count((*it).v)){
				compare(0, (*it).u, (*it).v, (*it).x, (*it).y, l, um);
				cnt_remain--;
				it = remain.erase(it);
			}
			else{
				++it;
			}
		}
	}
	vector<int> ans(n + 1);
	for(int p : l){
		ans[p] = n--;
	}
	for(auto it = next(ans.begin()); it != ans.end(); ++it){
		cout << *it << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		tree();
	}
	return 0;
}
