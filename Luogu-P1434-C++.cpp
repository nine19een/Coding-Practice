// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1434
// Author:   nine19een
// Date:     2025-07-28

#include <bits/stdc++.h>
using namespace std;
struct Point{
	int x, y;
};
int m, n;
int a[105][105], dp[105][105];
int max_dp = 0;

int isAvailable(Point p, int height){
	if(p.x < 1 || p.x > n || p.y < 1 || p.y > m){
		return 2;
	}
	if(a[p.x][p.y] >= height){
		return 2;
	}
	if(dp[p.x][p.y] != 0){
		return 0;
	}
	return 1;
}

int LENGTH(Point p){
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	int max_length = 0;
	for(int i = 0; i <= 3; i++){
		Point newpoint = {p.x + dx[i], p.y + dy[i]};
		if(isAvailable(newpoint, a[p.x][p.y]) == 2){
			continue;
		}		
		if(isAvailable(newpoint, a[p.x][p.y]) == 0){
			max_length = max(max_length, dp[newpoint.x][newpoint.y]);
		}
		if(isAvailable(newpoint, a[p.x][p.y]) == 1){
			max_length = max(max_length, LENGTH(newpoint));
		}
	}
	dp[p.x][p.y] = max_length + 1;
	return dp[p.x][p.y];
}

int main(){
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}		
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(dp[i][j] != 0){
				continue;
			}
			Point q = {i, j};
			max_dp = max(max_dp, LENGTH(q));
		}		
	}	
	cout << max_dp;
	return 0;
}

