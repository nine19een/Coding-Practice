// Problem:  opj 1755 菲波那契数列
// Link:     http://noi.openjudge.cn/ch0202/1755/
// Author:   nine19een
// Date:     2025-07-12

#include<bits/stdc++.h>
using namespace std;
int save[25] = {0};
int fib(int a){
	if(save[a] != 0){
		return save[a];
	}	
	if(a == 1 || a == 2){
		save[a] = 1;
		return save[a];
	}
	save[a] = fib(a-1) + fib(a-2);
	return save[a];
}
int n, A[10005];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i++){
		cout << fib(A[i]) << endl;
	}
	return 0;
}
