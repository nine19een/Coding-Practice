// Problem:  Luogu P1046 [NOIP 2005 普及组] 陶陶摘苹果
// Link:     https://www.luogu.com.cn/problem/P1046
// Author:   nine19een
// Date:     2025-07-02

#include<bits/stdc++.h>
using namespace std;
int a[10],h,n;
int main(){
	for(int i = 1 ; i <= 10 ; i++) cin >> a[i];
	cin >> h;
	h += 30;
	int n = 0;
	for(int i = 1 ; i <= 10 ; i++){
		if(h >= a[i]) n++;
	}cout << n;
	return 0;
}
