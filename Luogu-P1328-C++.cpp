// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1328
// Author:   nine19een
// Date:     2025-07-22

#include<bits/stdc++.h>
using namespace std;
int n, ta, tb;
int a[205] = {0}, b[205] = {0};
int scoreA = 0, scoreB = 0;

void match(int a, int b){
	if(a == b){
		return;
	}
	if((a == 0 && b == 1) || (a == 0 && b == 4) || (a == 1 && b == 2) || (a == 1 && b == 4) || (a == 2 && b == 3)){
		scoreB++;
		return;
	}
	if((a == 1 && b == 0) || (a == 4 && b == 0) || (a == 2 && b == 1) || (a == 4 && b == 1) || (a == 3 && b == 2)){
		scoreA++;
		return;
	}
	if((a == 0 && b == 2) || (a == 0 && b == 3) || (a == 1 && b == 3) || (a == 2 && b == 4) || (a == 3 && b == 4)){
		scoreA++;
		return;
	}	
	if((a == 2 && b == 0) || (a == 3 && b == 0) || (a == 3 && b == 1) || (a == 4 && b == 2) || (a == 4 && b == 3)){
		scoreB++;
		return;
	}
}

int main(){
	cin >> n >> ta >> tb;
	for(int i = 1; i <= ta; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= tb; i++){
		cin >> b[i];
	}
	int ai = 1, bi = 1;
	for(int i = 1; i <= n; i++){
		match(a[ai], b[bi]);
		ai++;
		bi++;
		if(ai == ta + 1){
			ai = 1;
		}
		if(bi == tb + 1){
			bi = 1;
		}
	}
	cout << scoreA << " " << scoreB;
	return 0;
}
