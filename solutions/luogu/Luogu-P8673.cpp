// Problem:  Luogu P8673 [蓝桥杯 2018 国 C] 迷宫与陷阱
// Link:     https://www.luogu.com.cn/problem/P8673
// Author:   nine19een
// Date:     2025-08-29

#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x, y, d, k;
};
int N, K;
char maze[1005][1005];
int buff[1005][1005];
bool visited[1005][1005];
queue<Point>q;

bool Available(Point p){
	if(p.x < 1 || p.x > N || p.y < 1 || p.y > N || maze[p.x][p.y] == '#'){
		return false;
	}
	else if(!visited[p.x][p.y]){
		if(maze[p.x][p.y] == '.' || maze[p.x][p.y] == '%' || (maze[p.x][p.y] == 'X' && p.k > 0)){
			return true;
		}
	}
	else if(visited[p.x][p.y]){
		if(p.k > buff[p.x][p.y]){
			return true;
		}
	}
	return false;
}

void Visit(Point old_p){
	int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	for(int i = 0; i <= 3; ++i){
		Point new_p = {old_p.x + dx[i], old_p.y + dy[i], old_p.d + 1, old_p.k};
		if(maze[new_p.x][new_p.y] == '%'){
			new_p.k = K + 1;
		}
		else{
			new_p.k -= (new_p.k > 0) ? 1 : 0;
		}
		if(Available(new_p)){
			visited[new_p.x][new_p.y] = true;
			buff[new_p.x][new_p.y] = new_p.k;
			q.push(new_p);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	memset(buff, -1, sizeof(buff));
	cin >> N >> K;
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			cin >> maze[i][j];
		}
	}
	visited[1][1] = true;
	Point maze_start = {1, 1, 0, 0};
	q.push(maze_start);
	visited[maze_start.x][maze_start.y] = true;
	while(!q.empty()){
		Point visit_p = q.front();
		q.pop();
		if(visit_p.x == N && visit_p.y == N){
			cout << visit_p.d;
			return 0;
		}
		Visit(visit_p);		
	}
	cout << -1;
	return 0;
}
