// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P11011
// Author:   nine19een
// Date:     2025-09-11

#include<bits/stdc++.h>
using namespace std;

int n, m, a[1005][1005], cnt;
unordered_map<int, vector<int>> um1;
unordered_map<int, vector<int>> um2;

void Cnt(unordered_map<int, vector<int>>& um){
	for(auto& p : um){
		sort(p.second.begin(), p.second.end());
		um[p.first].push_back(-1);
		int check_num = p.second.front();
		int cnt_num = 0;
		for(int q : p.second){
			if(q == check_num){
				cnt_num++;
			}
			else{
				check_num = q;
				cnt += cnt_num * (cnt_num - 1);
				cnt_num = 1;
			}
		}		
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[i][j];
			um1[i + j].push_back(a[i][j]);
			um2[i - j].push_back(a[i][j]);
		}
	}
	Cnt(um1);
	Cnt(um2);
	cout << cnt;
	return 0;
}
