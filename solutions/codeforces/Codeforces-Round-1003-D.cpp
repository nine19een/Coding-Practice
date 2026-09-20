// Problem:  Codeforces Round 1003 D. Skibidus and Sigma
// Link:     https://codeforces.com/contest/2065/problem/D
// Author:   nine19een
// Date:     2025-07-27

#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n, m;
		cin >> n >> m;
		long long score = 0;	
		long long sum_per[n + 5];
		long long score_per[n + 5];
		for(int j = 1; j <= n; j++){
			sum_per[j] = 0;
			score_per[j] = 0;
			for(int k = 1; k <= m; k++){
				int ele;
				cin >> ele;
				sum_per[j] += ele;
				score_per[j] += sum_per[j];
			}
			score += score_per[j];
		}
		sort(sum_per + 1, sum_per + n + 1, greater<long long>());
		for(int j = 1; j <= n - 1; j++){
			score += (n - j) * m * sum_per[j];
		}
		cout << score << endl;
	}
	return 0;
}

