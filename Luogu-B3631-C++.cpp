// Problem:  Luogu B3631 单向链表
// Link:     https://www.luogu.com.cn/problem/B3631
// Author:   nine19een
// Date:     2025-08-24

#include<bits/stdc++.h>
using namespace std;

list<int>l = {1};
unordered_map<int, list<int>::iterator>m;
int q;

void Ope(int num){
	switch(num){
		case 1:{
			int search_num, insert_num;
			cin >> search_num >> insert_num;
			auto insert_it = m[search_num];
			insert_it++;
			m[insert_num] = l.insert(insert_it, insert_num);
			break;
		}
		case 2:{
			int search_num;
			cin >> search_num;
			auto next_it = m[search_num];
			next_it++;
			if(next_it == l.end()){
				cout << 0 << '\n';
			}
			else{
				cout << *next_it << '\n';
			}
			break;
		}		
		case 3:{
			int erase_num;
			cin >> erase_num;
			auto erase_it = m[erase_num];
			erase_it++;
			l.erase(erase_it);
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	auto it_1 = l.begin();
	m[1] = it_1;
	cin >> q;
	while(q--){
		int num;
		cin >> num;
		Ope(num);
	}
	return 0;
}
