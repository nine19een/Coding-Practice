// Problem:  Codeforces Round 1017 B. Bobritto Bandito
// Link:     https://codeforces.com/contest/2094/problem/B
// Author:   nine19een
// Date:     2025-08-07

#include <bits/stdc++.h>
using namespace std;
int t;
int m[105], n[105], l[105], r[105];

void Spread(int i){
	int ll = 0, rr = 0;
	for(int j = 1; j <= m[i]; j++){
		if(rr < r[i]){
			rr++;
		}
		else{
			ll--;
		}
	}
	cout << ll << " " << rr << endl;
	return;
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n[i] >> m[i] >> l[i] >> r[i];
	}
	for(int i = 1; i <= t; i++){
		Spread(i);
	}
	return 0;
}
