// Problem:  Luogu P1540 [NOIP 2010 提高组] 机器翻译
// Link:     https://www.luogu.com.cn/problem/P1540
// Author:   nine19een
// Date:     2025-09-17

#include<bits/stdc++.h>
using namespace std;

int m, n, cnt;
set<int> s;
queue<int> q;

void OP(int x, set<int>& s, queue<int>& q){
	int size_s = s.size();
	int size_q = q.size();
	if(!s.count(x)){
		if(size_s == m){
			s.erase(q.front());
			q.pop();
		}
		s.insert(x);
		q.push(x);
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> m >> n;
	while(n--){
		int num;
		cin >> num;
		OP(num, s, q);
	}
	cout << cnt;
	return 0;
}
