// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1002
// Author:   nine19een
// Date:     2025-07-29

#include <bits/stdc++.h>
using  namespace std;
struct Point{
	int x, y;
};
Point horse, B;
long long chessboard[25][25];

bool isAvailable(Point p){
	if(p.x < 0 || p.x > B.x || p.y < 0 || p.y > B.y){
		return false;
	}
	return true;
}

void rideHorse(Point h){
	int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
	int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	for(int i = 0; i <= 7; i++){
		Point occupy = {h.x + dx[i], h.y + dy[i]};
		if(isAvailable(occupy)){
			chessboard[occupy.x][occupy.y] = 0;
		}
	}
	return;
}

long long soldierMove(Point p){
	Point above = {p.x - 1, p.y};
	Point left = {p.x, p.y - 1};
	if(chessboard[above.x][above.y] == -1){
		chessboard[above.x][above.y] = soldierMove(above);
	}
	if(chessboard[left.x][left.y] == -1){
		chessboard[left.x][left.y] = soldierMove(left);
	}
	chessboard[p.x][p.y] = chessboard[above.x][above.y] + chessboard[left.x][left.y];
	return chessboard[p.x][p.y];
}

int main(){
	memset(chessboard, -1, sizeof(chessboard));
	Point soldier = {0, 0};
	chessboard[soldier.x][soldier.y] = 1;
	cin >> B.x >> B.y >> horse.x >> horse.y;
	chessboard[horse.x][horse.y] = 0;
	rideHorse(horse);
	if(chessboard[0][0] == 0 || chessboard[B.x][B.y] == 0){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= B.x; i++){
		if(chessboard[i][0] != 0){
			chessboard[i][0] = chessboard[i-1][0];
		}
	}
	for(int i = 1; i <= B.y; i++){
		if(chessboard[0][i] != 0){
			chessboard[0][i] = chessboard[0][i-1];
		}
	}
	cout << soldierMove(B);
	return 0;
}

