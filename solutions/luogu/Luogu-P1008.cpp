// Problem:  Luogu P1008 [NOIP 1998 普及组] 三连击
// Link:     https://www.luogu.com.cn/problem/P1008
// Author:   nine19een
// Date:     2025-09-14

#include<bits/stdc++.h>
using namespace std;

bool Right(int x, int y, int z){
	int cnt[15];
	memset(cnt, 0, sizeof(cnt));
	while(x != 0){
		int X = x;
		int single_num = x % 10;
		if(cnt[single_num] || single_num == 0){
			return false;
		}
		cnt[single_num]++;
		x /= 10;
	}
	while(y != 0){
		int Y = y;
		int single_num = y % 10;
		if(cnt[single_num] || single_num == 0){
			return false;
		}
		cnt[single_num]++;
		y /= 10;
	}
	while(z != 0){
		int Z = z;
		int single_num = z % 10;
		if(cnt[single_num] || single_num == 0){
			return false;
		}
		cnt[single_num]++;
		z /= 10;
	}	
	return true;	
}

int main(){
	for(int i = 123; i < 333; ++i){
		int x = i, y = 2 * i, z = 3 * i;
		if(Right(x, y, z)){
			cout << x << " " << y << " " << z << endl;
		}
	}
	return 0;
}
