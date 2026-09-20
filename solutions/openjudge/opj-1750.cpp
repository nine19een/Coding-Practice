// Problem:  opj 1750 全排列
// Link:     http://noi.openjudge.cn/ch0202/1750/
// Author:   nine19een
// Date:     2025-07-14

#include <bits/stdc++.h>
using namespace std;
void solve(vector<char>rest, vector<char>newl){
	if(rest.empty()){
		for(char c : newl){
	 		cout << c;
		}
		cout << endl;
		return;	 			
	}
	for(int i = 0; i < rest.size(); i++){	
	 	char letter = rest[i];
	 	rest.erase(rest.begin() + i);
	 	newl.push_back(letter);
	 	solve(rest, newl);
	 	rest.insert(rest.begin() + i, letter);
	 	newl.pop_back();
	 	continue;
	}
	return;
}
char str[10] = {0};
vector<char>Rest;
vector<char>newL;
int  main(){
	Rest.reserve(10);
	newL.reserve(10);
	cin >> str;
	int Len = strlen(str);
	for(int i = 0; i < Len; i++){
		Rest.push_back(str[i]);
	}
	solve(Rest, newL);
	return 0;
}
