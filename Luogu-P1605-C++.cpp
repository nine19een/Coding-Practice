// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1605
// Author:   nine19een
// Date:     2025-07-17

#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x, y;
};
int n, m, t, cnt = 0;
Point T[15];
Point S, F;
char maze[10][10];
bool visited[10][10];

bool validate(Point P){
	if(P.x < 1 || P.x > n || P.y < 1 || P.y > m || maze[P.x][P.y] == 'T' || visited[P.x][P.y]){
		return false;
	}
	else{
		return true;
	}
}

void walk(Point P){
	if(maze[P.x][P.y] == 'F'){
		cnt++;
		return;
	}
	visited[P.x][P.y] = true;
	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	for(int i = 0; i < 4; i++){
		Point newpoint;
		newpoint = {P.x + dx[i], P.y + dy[i]};
		if(validate(newpoint)){
			walk(newpoint);
		}
	}
	visited[P.x][P.y] = false;
	return;
}

int main(){
	memset(maze, 0, sizeof(maze));
	memset(T, 0, sizeof(T));
	memset(visited, 0, sizeof(visited));
	cin >> n >> m >> t;
	cin >> S.x >> S.y >> F.x >> F.y;
	maze[S.x][S.y] = 'S';
	maze[F.x][F.y] = 'F';
	for(int i = 1; i <= t; i++){
		cin >> T[i].x >> T[i].y;
		maze[T[i].x][T[i].y] = 'T';
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(maze[i][j] != 'S' && maze[i][j] != 'F' && maze[i][j] != 'T'){
				maze[i][j] = '.';
			}
		}
	}
	walk(S);
	cout << cnt;
	return 0;
}
