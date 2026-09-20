// Problem:  Luogu P1941 [NOIP 2014 提高组] 飞扬的小鸟
// Link:     https://www.luogu.com.cn/problem/P1941
// Author:   nine19een
// Date:     2025-08-16

#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e9 + 5;
int N, M, K, ans = maxn, cnt_pipe[10005], cnt, cnt_p = 0;
int dp[10005][1005];
struct flyORfall{
	int x, y;
};
flyORfall n[10005];

void FLY(){
	for(int i = 1; i <= N; i++){
		dp[i][0] = -1;
		cnt = 0;
		if(i == 1){
			for(int j = 1; j <= M; j++){
				if(dp[i][j] == -1){
					continue;
				}
				if(j + n[1].y <= M){
					dp[1][j] = 0;
					cnt++;
					continue;
				}
				else{
					if(j - n[1].x >= 0){
						dp[1][j] = 1;
						cnt++;
						continue;
					}
					else{
						dp[1][j] = -1;
						cnt++;
						continue;
					}
				}
			}
			if(cnt == 0){
				cout << 0 << endl << cnt_pipe;
				return;
			}
			else{
				cnt_pipe[1]++;
			}
			continue;
		}
		for(int r = 0; r < n[i].x; r++){
			deque<int>q;
			int jm = M + n[i].x;
			for(int j = r; j <= jm; j += n[i].x){
				if(j == 0){
					continue;
				}
				if(j > M && cnt_pipe[i] == 0){
					continue;
				}
				if(j - n[i].x > 0 && dp[i - 1][j - n[i].x] != -1){
					while(!q.empty() && dp[i - 1][j - n[i].x] - j / n[i].x + 1 < q.back()){
						q.pop_back();
					}
					q.push_back(dp[i - 1][j - n[i].x] - j / n[i].x + 1);
				}
				if(j > M){
					if(q.empty()){
						continue;
					}
					if(dp[i][M] == 0){
						dp[i][M] = q.front() + j / n[i].x;
						cnt++;
						continue;
					}
					else{
						dp[i][M] = min(dp[i][M], q.front() + j / n[i].x);
						cnt++;
						continue;
					}
				}
				if(dp[i][j] == -1){
					continue;
				}
				if((j + n[i].y <= M && dp[i - 1][j + n[i].y] != -1) && !q.empty()){
					dp[i][j] = min(dp[i - 1][j + n[i].y], q.front() + j / n[i].x);
					cnt++;
					continue;					
				}
				else if((j + n[i].y <= M && dp[i - 1][j + n[i].y] != -1) && q.empty()){
					dp[i][j] = dp[i - 1][j + n[i].y];
					cnt++;
					continue;					
				}
				else if(!(j + n[i].y <= M && dp[i - 1][j + n[i].y] != -1) && !q.empty()){
					if (j == M) {
						if (dp[i][M] == 0) {
							dp[i][j] = q.front() + j / n[i].x;
						}
						else {
							dp[i][j] = min(dp[i][j], q.front() + j / n[i].x);
						}
						continue;
					}
					dp[i][j] = q.front() + j / n[i].x;
					cnt++;
					continue;
				}
				else{
					if(j == M){
						continue;
					}
					dp[i][j] = -1;
					continue;
				}
			}
		}
		if(cnt == 0){
			for(int k = 1; k <= i; k++){
				cnt_p += cnt_pipe[k];
			}
			cout << 0 << endl << cnt_p;
			cout << endl;
			return;
		}
		else{
			cnt_pipe[i]++;
		}
	}
	for(int k = 1; k <= M; k++){
		if(dp[N][k] != -1) {
			ans = min(ans, dp[N][k]);
		}
	}
	cout << 1 << endl << ans;
	cout << endl;
	return;
}

int main(){
	memset(cnt_pipe, -1, sizeof(cnt_pipe));
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		cin >> n[i].x >> n[i].y;
	}
	for(int i = 1; i <= K; i++){
		int p, l, h;
		cin >> p >> l >> h;
		for(int j = 0; j <= l; j++){
			dp[p][j] = -1;
		} 
		for(int j = h; j <= M; j++){
			dp[p][j] = -1;
		}
		cnt_pipe[p]++;		
	}
	FLY();
	return 0; 
}
