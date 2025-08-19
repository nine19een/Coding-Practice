// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P5266
// Author:   nine19een
// Date:     2025-08-20

#include<bits/stdc++.h>
using namespace std;

int n, num;
unordered_map<string, int>ss_map;

void EXEC(){
	string s;
	if(num == 1){
		int score;
		cin >> s >> score;
		ss_map[s] = score;
		cout << "OK" << endl;
	}
	else if(num == 2){
		cin >> s;
		auto it = ss_map.find(s);
		if(it != ss_map.end()){
			cout << it->second << endl;
		}
		else{
			cout << "Not found" << endl;
		}
	}
	else if(num == 3){
		cin >> s;
		if(ss_map.count(s)){
			ss_map.erase(s);
			cout << "Deleted successfully" << endl;
		}
		else{
			cout << "Not found" << endl;
		}
	}
	else{
		cout << ss_map.size() << endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while(n--){
		cin >> num;
		EXEC();
	}
	return 0;
}
