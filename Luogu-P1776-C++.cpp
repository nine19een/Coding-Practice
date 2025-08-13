// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1776
// Author:   nine19een
// Date:     2025-08-13

#include <bits/stdc++.h>
using namespace std;
int const maxn = 4e4 + 5, maxm = 1e5 + 5;
using ll = long long;
int N, W;
struct Treasure{
	ll v, w, m;
};
struct Q{
	ll v, w;
};
Treasure n[105];
ll dp[maxn];

void DP(int i){
	for(int r = 0; r < n[i].w; r++){
		deque<Q>q;
		for(int j = r; j <= W; j += n[i].w){
			ll old_v = dp[j] - j / n[i].w * n[i].v;	
			if(!q.empty() && j - n[i].m * n[i].w > q.front().w){
				q.pop_front();
			}
			if(!q.empty()){
				dp[j] = max(dp[j], q.front().v + j / n[i].w * n[i].v);
			}
			while(!q.empty() && old_v >= q.back().v){
				q.pop_back();
			}
			q.push_back({old_v, j});
		}
	}
	return;
}

int main(){
	cin >> N >> W;
	for(int i = 1; i <= N; i++){
		cin >> n[i].v >> n[i].w >> n[i].m;
	}
	for(int i = 1; i <= N; i++){
		DP(i);
	}
	cout << dp[W];
	return 0;
}

