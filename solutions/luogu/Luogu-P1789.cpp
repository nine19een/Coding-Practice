// Problem:  Luogu P1789 【Mc生存】插火把
// Link:     https://www.luogu.com.cn/problem/P1789
// Author:   nine19een
// Date:     2025-10-21

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

struct Point{
	int x, y;
};

int ground[maxn][maxn], n, m, k, cnt;

bool available(Point check_p){
	return (check_p.x >= 1 && check_p.x <= n && check_p.y >= 1 && check_p.y <= n);
}

void torch(Point T){
	int dx[] = {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
	int dy[] = {0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0};
	for(int i = 0; i < 13; ++i){
		Point new_p = {T.x + dx[i], T.y + dy[i]};
		if(available(new_p)){
			ground[new_p.x][new_p.y] = 1;
		}
	}
}

void fluorite(Point F){
	Point start = {F.x - 2, F.y - 2};
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			Point new_f = {start.x + i, start.y + j};
			if(available(new_f)){
				ground[new_f.x][new_f.y] = 1;
			}
		}
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		torch({x, y});
	}
	for(int i = 1; i <= k; ++i){
		int x, y;
		cin >> x >> y;
		fluorite({x, y});
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cnt += ground[i][j] == 0 ? 1 : 0; 
		}
	}
	cout << cnt;
	return 0;
}
