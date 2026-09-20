// Problem:  Codeforces Round 1074 B - Prefix Max
// Link:     https://codeforces.com/contest/2173/problem/B
// Author:   nine19een
// Date:     2026-01-18

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
	int n;
	cin >> n;
	int max_a = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		max_a = max(max_a, a);
	}
	cout << max_a * n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		op();
	}
	return 0;
}
