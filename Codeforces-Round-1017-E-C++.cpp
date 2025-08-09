// Problem:  Codeforces Round 1017 E. Boneca Ambalabu
// Link:     https://codeforces.com/contest/2094/problem/E
// Author:   nine19een
// Date:     2025-08-09

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

ll XOR(int cnt[], int num, int n){
	ll result = 0;
	for(int i = 0; i < 30; i++){
		ll sum = 0;
		if((num >> i) & 1){
			sum += ((1ll * (n - cnt[30 - i])) << i);
		}
		else{
			sum += ((1ll * cnt[30 - i]) << i);
		}
		result += sum;
	}
	return result;
}

ll MAXXOR(int cnt[]){
	int n;
	cin >> n;
	int a[n + 5];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 0; j < 30; j++){
			cnt[30 - j] += ((a[i] >> j) & 1);
		}
	}
	ll maxSum = 0;
	for(int i = 1; i <= n; i++){
		maxSum = max(XOR(cnt, a[i], n), maxSum);
	}
	return maxSum;
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		int cnt[35] = {0};
		cout << MAXXOR(cnt) << endl;
	}
	return 0;
}

