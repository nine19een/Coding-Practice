// Problem:  Luogu P12288 [蓝桥杯 2024 国 Java A] 栈
// Link:     https://www.luogu.com.cn/problem/P12288
// Author:   nine19een
// Date:     2025-09-05

#include<bits/stdc++.h>
using namespace std;

int n, cnt;
unordered_map<int, list<int>::iterator> um;
list<int> l;

bool isODDpair(list<int>::iterator left, list<int>::iterator right){
	return (*left & 1) ^ (*right & 1);
}

void addODDpair(list<int> &l){
	auto it = prev(l.end());
	if(it != l.begin()){
		auto prev_it = prev(it);
		if(isODDpair(it, prev_it)){
			cnt++;
		}
	}
}

void subODDpair(list<int> &l, list<int>::iterator it){
	bool has_prev = (it != l.begin());
	bool has_next = (it != prev(l.end()));
	auto prev_it = has_prev ? prev(it) : l.end();
	auto next_it = has_next ? next(it) : l.end();
	if(has_prev && isODDpair(it, prev_it)){
		cnt--;
	}
	if(has_next && isODDpair(it, next_it)){
		cnt--;
	}
	if(has_prev && has_next && isODDpair(prev_it, next_it)){
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		if(um.find(num) == um.end()){
			l.push_back(num);
			addODDpair(l);
			um[num] = prev(l.end());
		}
		else{
			auto it = um[num];
			subODDpair(l, it);
			l.erase(it);
			l.push_back(num);
			addODDpair(l);
			um[num] = prev(l.end());
		}
		cout << cnt << '\n';
	}
	return 0;
}
