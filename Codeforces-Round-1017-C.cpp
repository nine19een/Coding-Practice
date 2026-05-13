// Problem:  Codeforces Round 1017 C. Brr Brrr Patapim
// Link:     https://codeforces.com/contest/2094/problem/C
// Author:   nine19een
// Date:     2025-08-07

#include <bits/stdc++.h>
using namespace std;
int t;
int n[205];

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n[i];
		int const maxn = n[i] + 5;
		int g[maxn][maxn];
		for(int p = 1; p <= n[i]; p++){
			for(int q = 1; q <= n[i]; q++){
				cin >> g[p][q];
			}
		}
		int const maxm = 2 * n[i] + 5;
		int passcode[maxm];
		int x = 1, y = 1;
		int num[maxm] = {0};
		for(int j = 2; j <= maxm - 5; j++){
			passcode[j] = g[x][y];
			num[g[x][y]]++;
//			cout << j << "*" << x << "|" << y  << "*" << g[x][y] << " ";
			if(j % 2 == 0){
				y++;
			}
			else{
				x++;
			}
		}
		int code_1;
		for(int k = 1; k <= maxm - 5; k++){
			if(num[k] == 0){
				code_1 = k;
			}
		}
		passcode[1] = code_1;
		for(int r = 1; r <= maxm - 5; r++){
			cout << passcode[r] << " ";
		}
		cout << endl;
	}
	return 0;
}
