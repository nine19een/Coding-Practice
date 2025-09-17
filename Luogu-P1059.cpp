// Problem:  洛谷 P1059 [NOIP 2006 普及组] 明明的随机数
// Link:     https://www.luogu.com.cn/problem/P1059
// Author:   nine19een
// Date:     2025-09-17

#include<bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		s.insert(num);
	}	
	int size_s = s.size();
	cout << size_s << '\n';
	for(int p : s){
		cout << p << " ";
	}
	return 0;
}
