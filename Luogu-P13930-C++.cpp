// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P13930
// Author:   nine19een
// Date:     2025-09-07

#include<bits/stdc++.h>
using namespace std;

int maxn = 1e6 + 5;
string S, ans;
int cnt[35], cnt_max;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> S;
	for(char p : S){
		cnt[p - 'A']++;
	}
	for(int i = 0; i <= 25; ++i){
		cnt_max = max(cnt_max, cnt[i]);
	}
	for(int i = 0; i <= 25; ++i){
		if(cnt[i] == cnt_max){
			ans += (i + 'A');
		}
	}
	for(char p : ans){
		cout << p;
	}	
	return 0;
}
