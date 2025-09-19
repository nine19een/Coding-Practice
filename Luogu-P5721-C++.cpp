// Problem:  Luogu P5721 【深基4.例6】数字直角三角形
// Link:     https://www.luogu.com.cn/problem/P5721
// Author:   nine19een
// Date:     2025-07-02

#include<bits/stdc++.h>
using namespace std;
int arr[100],n,m;
int main(){
	cin >> n;
	m = (1 + n) * n / 2;
	int t = 0;
	for( int i = 1 ; i <= m ; i++){
		arr[i] = i;
	} 
	for( int j = n ; j > 0 ; j--){
		for( int i = 1 ; i <= j ; i++){
			t++;
			if(t < 10){
				cout << "0" << t;
			}else cout << t;
		}cout << "\n";
	}
	return 0;
}
