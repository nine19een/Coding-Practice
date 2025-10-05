// Problem:  丁香花分形
// Link:     还没上传
// Author:   nine19een
// Date:     2025-10-06

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e3 + 5;

int n, a_pic = 3, a_temp = 3, b[10];
char pic[maxn][maxn];
char temp[maxn][maxn];

bool isEven(int num){
	return !(num & 1);
}

void draw(int x, int y){
	for(int i = 1; i <= a_temp; ++i){
		for(int j = 1; j <= a_temp; ++j){
			if(pic[x + i - 1][y + j - 1] != 'o'){
				pic[x + i - 1][y + j - 1] = temp[i][j];
			}
		}
	}
}

void update_a(int x){
	if(!isEven(x)){
		a_pic *= 2;
		b[x] = a_pic;
	}
	else{
		if(x == 2){
			a_pic = a_temp * 3 - 2;
		}
		else{
			a_pic = a_pic + (a_pic - b[x - 3]) * 2;
		}
	}
}

void update_temp(){
	for(int i = 1; i <= a_pic; ++i){
		for(int j = 1; j <= a_pic; ++j){
			if (pic[i][j] == 0) {
				pic[i][j] = ' ';
			}
			temp[i][j] = pic[i][j];
		}	
	}
	a_temp = a_pic;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	temp[1][1] = ' ', temp[1][2] = 'o', temp[1][3] = ' ', temp[2][1] = 'o', temp[2][2] = ' ', temp[2][3] = 'o', temp[3][1] = ' ', temp[3][2] = 'o', temp[3][3] = ' ';
	cin >> n;
	for(int i = 1; i <= n; ++i){
		update_a(i);
		for (int j = 1; j <= a_temp; ++j) {
			memset(pic[j], 0, sizeof pic[j]);
		}
		if(!isEven(i)){
			draw(1, 1);
			draw(1, 1 + a_temp);
			draw(1 + a_temp, 1);
			draw(1 + a_temp, 1 + a_temp);
		}
		else{
			if(i == 2){
				draw(1, a_temp);
				draw(a_temp, 1);
				draw(a_temp, 2 * a_temp - 1);
				draw(2 * a_temp - 1, a_temp);
			}
			else{
				draw(1, a_temp - (b[i - 3] - 1));
				draw(a_temp - (b[i - 3] - 1), 1);
				draw(a_temp - (b[i - 3] - 1), 2 * a_temp - (2 * b[i - 3] - 1));
				draw(2 * a_temp - (2 * b[i - 3] - 1), a_temp - (b[i - 3] - 1));
			}
		}
		update_temp();
	}
//	cout << a_pic << '\n';
	for(int i = 1; i <= a_pic; ++i){
		for(int j = 1; j <= a_pic; ++j){
			cout << " " << pic[i][j];
		}
		cout << '\n';
	}
	return 0;
}
