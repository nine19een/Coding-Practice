// Problem:  Luogu P1596 [USACO10OCT] Lake Counting S
// Link:     https://www.luogu.com.cn/problem/P1596
// Author:   nine19een
// Date:     2025-07-15

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;
int visit_pool[maxn][maxn];  
char field[maxn][maxn];
int n, m;
struct Point{
	int x, y;
};
Point water[maxn*maxn];
queue<Point>q;
int c_water = 0, c_pool = 0;
bool isPool(Point a){
	if (a.x > n || a.x < 1 || a.y > m || a.y < 1 || visit_pool[a.x][a.y] != 0 || field[a.x][a.y] == '.'){
		return false;
	}
	else{
		return true;
	}
}
void Expand(Point a){
	int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
	for(int k = 0; k < 8; k++){
		Point next_a = {a.x + dx[k], a.y + dy[k]};
		if(isPool(next_a)){
			visit_pool[next_a.x][next_a.y] = c_pool;
			q.push(next_a);
		}
	}
}
int main(){
	memset(field, 0, sizeof(field));
	memset(visit_pool, 0, sizeof(visit_pool));	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> field[i][j];
			if(field[i][j] == 'W'){
				c_water++;
				water[c_water] = {i, j};
			}
		}
	}
	for(int i = 1; i <= c_water; i++){
		if(visit_pool[water[i].x][water[i].y] != 0){
			continue;
		}
		c_pool++;
		q.push(water[i]);
		while(!q.empty()){
			Point cur = q.front();
			q.pop();
			visit_pool[cur.x][cur.y] = c_pool;
			Expand(cur);
		}
	}
	cout << c_pool;
	return 0;
}
