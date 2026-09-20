// Problem:  Luogu P8630 [蓝桥杯 2015 国 B] 密文搜索
// Link:     https://www.luogu.com.cn/problem/P8630
// Author:   nine19een
// Date:     2025-08-20

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 1048580;

char s[maxn];
int n;
ll ans = 0;
char c;
deque<char>str;
vector<char>str_sort;
vector<char>pw;
unordered_map<string, ll>hash_map;

void Store(){
	for(int i = 0; i <= 7; ++i){
		str.push_back(s[i]);
	}
	for(int i = 8; i <= 1048579; ++i){
		str_sort.assign(str.begin(), str.end());
		sort(str_sort.begin(), str_sort.end());
		string key1(str_sort.begin(), str_sort.end());
		hash_map[key1]++;
		if(s[i] == 0){
			break;
		}
		str.pop_front();
		str.push_back(s[i]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	str_sort.reserve(10);
	pw.reserve(10);
	cin >> s >> n;
	Store();
	while(n--){
		for(int i = 1; i <= 8; i++){
			cin >> c;
			pw.push_back(c);
		}
		sort(pw.begin(), pw.end());
		string key2(pw.begin(), pw.end());
		ans += hash_map[key2];
		pw.clear();
	}
	cout << ans;
	return 0;
}
