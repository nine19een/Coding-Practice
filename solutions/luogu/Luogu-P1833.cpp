// Problem:  Luogu P1833 樱花
// Link:     https://www.luogu.com.cn/problem/P1833
// Author:   nine19een
// Date:     2025-08-16

#include<bits/stdc++.h>
using namespace std;

char one, two;
int h1, h2, min1, min2, time_, N;
int dp[10005][1005];
struct Tree{
	int t, c, p;
};
Tree n[10005];
struct Q{
	int val, k;
};

void Sakura(){
	for(int i = 1; i <= N; i++){
		for(int r = 0; r < n[i].t; r++){
			deque<Q>q;
			for(int j = r; j <= time_; j += n[i].t){
				if(n[i].p == 0){
					while(!q.empty() && dp[i - 1][j] - j / n[i].t * n[i].c >= q.back().val){
						q.pop_back();
					}
					q.push_back({dp[i - 1][j] - j / n[i].t * n[i].c, j / n[i].t});
					dp[i][j] = max(dp[i - 1][j], q.front().val + j / n[i].t * n[i].c);
				}
				else{
					if((j / n[i].t - q.front().k) > n[i].p){
						q.pop_front();
					}	
					while(!q.empty() && dp[i - 1][j] - j / n[i].t * n[i].c >= q.back().val){
						q.pop_back();
					}
					q.push_back({dp[i - 1][j] - j / n[i].t * n[i].c, j / n[i].t});
					dp[i][j] = max(dp[i - 1][j], q.front().val + j / n[i].t * n[i].c);
				}
			}
		}
	}
}
 
int main(){
	cin >> h1 >> one >> min1 >> h2 >> two >> min2 >> N;
	time_ = (h2 - h1) * 60 + min2 - min1;
	for(int i = 1; i <= N; i++){
		cin >> n[i].t >> n[i].c >> n[i].p;
	}
	Sakura();
	cout << dp[N][time_];
	return 0;
}
