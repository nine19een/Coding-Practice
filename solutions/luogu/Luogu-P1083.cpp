// Problem:  Luogu P1083 [NOIP 2012 提高组] 借教室
// Link:     https://www.luogu.com.cn/problem/P1083
// Author:   nine19een
// Date:     2025-08-07

#include <bits/stdc++.h>
using namespace std;

struct Order{
	int cost, start, end;
};
int n, m;

bool Check(int mid, int N, Order o[], int r[], int diff[]){
	int d[N];
	for(int i = 1; i <= N - 5; i++){
		d[i] = diff[i];
	}
	for(int i = 1; i <= mid; i++){
		d[o[i].start] -= o[i].cost;
		d[o[i].end + 1] += o[i].cost;
	}
	for(int i = 1; i <= N - 5; i++){
	}
	for(int i = 1; i <= N - 5; i++){
		int need_today;
		if(i == 1){
			need_today = d[1];
		}
		else{
			need_today += d[i];
		}
		if(need_today < 0){
			return false;
		} 
	}
	return true;
}

int main(){
	cin >> n >> m;
	int const N = n + 5, M = m + 5;
	int room[N], diff[N];
	Order order[M];
	for(int i = 1; i <= n; i++){
		cin >> room[i];
		if(i == 1){
			diff[i] = room[i];
		}
		else{
			diff[i] = room[i] - room[i - 1];
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> order[i].cost >> order[i].start >> order[i].end;
	}
	int left = 1, right = m;
	while(left <= right){
		int middle = (left + right) / 2;
		if(Check(middle, N, order, room, diff)){
			left = middle + 1;
		}
		else{
			right = middle - 1;
		}
	}
	if(left <= m && right >= 1){
		cout << -1 << endl << left;
	}
	else if(right < 1){
		cout << -1 << endl << 1;
	}
	else{
			cout << 0;
	}
	return 0;
}
