// Problem:  Luogu P1085 [NOIP 2004 普及组] 不高兴的津津
// Link:     https://www.luogu.com.cn/problem/P1085
// Author:   nine19een
// Date:     2025-07-03

#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10];
int main(){
	for( int i = 1 ; i <= 7 ; i++ ){
		cin >> a[i] >> b[i];
		c[i] = a[i] + b[i];
	}
	if( c[1] > 8 || c[2] > 8 || c[3] > 8 || c[4] > 8 || c[5] > 8 || c[6] > 8 || c[7] > 8 ){
	int t = 1;
	for( int i = 1 ; i <= 6 ; i++ ){
		if( c[i+1] - c[t] > 0 ){
			t = i + 1;
		}
		}cout << t;
	}else{
		cout << "0";
	}
	return 0; 
}
