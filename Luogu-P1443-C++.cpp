// Problem:  Luogu P1443 马的遍历
// Link:     https://www.luogu.com.cn/problem/P1443
// Author:   nine19een
// Date:     2025-08-25

#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x, y, d;
};
int n, m, x_start, y_start;
queue<Point>q;
unordered_map<int, int>visited;

int xyToll(int x, int y){
	return x * 401 + y;
}

bool Available(Point p, int xy){
	if(p.x < 1 || p.x > n || p.y < 1 || p.y > m || visited.count(xy)){
		return false;
	}
	return true;
}

void rideHorse(Point p){
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	for(int i = 0; i <= 7; ++i){
		int new_pd = p.d;
		new_pd++;
		Point footprint = {p.x + dx[i], p.y + dy[i], new_pd};
		int fp = xyToll(p.x + dx[i], p.y + dy[i]);
		if(Available(footprint, fp)){
			q.push(footprint);
			visited[fp] = footprint.d;
		}
	}
}

void printANS(){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			int xy = xyToll(i, j);
			if(!visited.count(xy)){
				cout << -1 << " ";
			}
			else{
				cout << visited[xy] << " ";
			}
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m >> x_start >> y_start;
	Point p_start = {x_start, y_start, 0};
	q.push(p_start);
	visited[xyToll(x_start, y_start)] = 0;
	while(!q.empty()){
		Point old_horse = q.front();
		rideHorse(old_horse);
		q.pop();
	}
	printANS();
	return 0;
}
