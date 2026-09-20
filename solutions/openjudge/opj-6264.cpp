// Problem:  opj 6264 走出迷宫
// Link:     http://noi.openjudge.cn/ch0205/6264/
// Author:   nine19een
// Date:     2025-07-14

#include <bits/stdc++.h>
using namespace std;
int m, n, si, sj;
int const maxn = 105;
char maze[maxn][maxn];
int deep[maxn][maxn];
struct point{int x, y;};
bool visited[maxn][maxn];
queue<point>q;
bool validate(point A){
	if(maze[A.x][A.y] == '#' || A.x > n || A.x < 1 || A.y > m || A.y < 1 || visited[A.x][A.y] == true){
		return false;
	}
	else{
		return true;
	}
}
void Expand(point A){
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	for(int i = 0; i < 4; i++){
		point next_a = {A.x + dx[i], A.y + dy[i]};
		if(validate(next_a)){
			visited[next_a.x][next_a.y] = true;
			deep[next_a.x][next_a.y] = deep[A.x][A.y] + 1;
			q.push(next_a);
		}
	}
}
int main(){
	memset(maze, 0, sizeof(maze));
	memset(visited, 0, sizeof(visited));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> maze[i][j];
			if(maze[i][j] == 'S'){
				si = i;
				sj = j;
			}
		}
	}
	point start_{si, sj};
	q.push(start_);
	visited[si][sj] = true;
	deep[si][sj] = 0;
	while(!q.empty()){
		point cur = q.front();
		q.pop();
		if(maze[cur.x][cur.y] == 'T'){
			cout << deep[cur.x][cur.y];
			break;
		}		
		Expand(cur);
	}
	return 0;
}