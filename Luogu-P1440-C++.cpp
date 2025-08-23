// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1440
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e6 + 5;
int n, m, a[maxn];
deque<pair<int, int>>q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freeopen
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << 0 << "\n";
	for(int i = 2; i <= n; i++){
		if(!q.empty() && q.front().second < i - m){
			q.pop_front();
		}
		while(!q.empty() && q.back().first >= a[i - 1]){
			q.pop_back();
		}
		q.push_back({a[i - 1], i - 1});
		cout << q.front().first << "\n";
	}
	return 0;
}
