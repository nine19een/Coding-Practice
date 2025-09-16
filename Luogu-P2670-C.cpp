// Problem:  洛谷 P2670 [NOIP 2015 普及组] 扫雷游戏
// Link:     https://www.luogu.com.cn/problem/P2670
// Author:   nine19een
// Date:     2025-09-16

#include<stdio.h>

int n, m, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
char map[105][105];

int Available(int x, int y){
	return (x >= 1 && x <= n && y >= 1 && y <= m) ? 1 : 0;
}

void check(int x, int y){
	if(map[x][y] == '*'){
		putchar('*');
		return;
	}
	int cnt = 0;
	for(int i = 0; i <= 7; ++i){
		int X = x + dx[i], Y = y + dy[i];
		if(Available(X, Y)){
			cnt += (map[X][Y] == '*') ? 1 : 0;
		}
	}
	printf("%d", cnt);
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){ 
			scanf(" %c", &map[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){ 
			check(i, j);
		}
		putchar('\n');
	}		
	return 0;
}
