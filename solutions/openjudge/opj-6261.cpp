// Problem:  opj 6261 汉诺塔问题
// Link:     http://noi.openjudge.cn/ch0202/6261/
// Author:   nine19een
// Date:     2025-07-12

#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char a, char b, char c){
	int m;
	if(n == 1){
		cout << a << "->" << n << "->" << b << endl;
	}
	else{
		hanoi(n - 1, a, c, b);
		cout << a << "->" << n << "->" << b << endl; 
		hanoi(n - 1, c, b, a);
	}
}
int N;
char A, B, C;
int main(){
	cin >> N;
	cin >> A >> B >> C;
	hanoi(N, A, B, C);
	return 0;
}
