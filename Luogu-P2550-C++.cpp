// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2550
// Author:   nine19een
// Date:     2025-07-16

#include<bits/stdc++.h>
using namespace std;
int n, cnt7 = 0, cnt6 = 0, cnt5 = 0, cnt4 = 0, cnt3 = 0, cnt2 = 0, cnt1 = 0;
int cnt[1005] = {0}, bingo[10] = {0}, bet[1005][10] = {0};
void check(int bingo[], int bet[], int &cnt){
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 7; j++){
			if(bingo[i] == bet[j]){
				cnt++;
			}
		}
	}
	return;	
}
int main(){
	cin >> n;
	for(int i = 1; i <= 7; i++){
		cin >> bingo[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 7; j++){
			cin >> bet[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		check(bingo, bet[i], cnt[i]);
	}
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 7){
			cnt7++;
		}
		if(cnt[i] == 6){
			cnt6++;
		}
		if(cnt[i] == 5){
			cnt5++;
		}
		if(cnt[i] == 4){
			cnt4++;
		}
		if(cnt[i] == 3){
			cnt3++;
		}
		if(cnt[i] == 2){
			cnt2++;
		}
		if(cnt[i] == 1){
			cnt1++;
		}
	}
	cout << cnt7 << " " << cnt6 << " " << cnt5 << " " << cnt4 << " " << cnt3 << " " << cnt2 << " " << cnt1; 
	return 0;
}
