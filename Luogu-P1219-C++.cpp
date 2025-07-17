// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1219
// Author:   nine19een
// Date:     2025-07-17

#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x, y;
};
int n, cnt = 0;
int ans[8][18];
vector<Point>queen;
bool line[18] = {0}, line1[30] = {0}, line2[30] = {0};

bool validate(Point P){
	if(line[P.y] || line1[P.x + P.y] || line2[P.x - P.y + n]){
		return false;
	}
	return true;
}

void occupy1(Point P){
	line[P.y] = true;
	line1[P.x + P.y] = true;
	line2[P.x - P.y + n] = true;
}

void occupy2(Point P){
	line[P.y] = false;
	line1[P.x + P.y] = false;
	line2[P.x - P.y + n] = false;
}

void chess(int j){
	for(int i = 1; i <= n; i++){
		Point check = {j, i};
		if(validate(check)){
			queen.push_back(check);
			if(queen.size() == n){
				cnt++;
				if(cnt <= 3){
					for(int k = 0; k < n; k++){
						ans[cnt][k] = queen[k].y;
					}
				}
				queen.pop_back();
				return;	
			}
			occupy1(check);
			chess(j + 1);
			queen.pop_back();
			occupy2(check);
		}
		else{
			continue;
		}	
	}
	return;
}

int main(){
	queen.reserve(18);
	cin >> n;
	chess(1);
	for(int k = 1; k <= 3; k++){
		for(int i = 0; i < n; i++){
			cout << ans[k][i] << " ";
		}
		cout << endl;
	}
	cout << cnt;
	return 0;
}
