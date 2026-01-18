// Problem:  Codeforces Round 1074 A - Perfect Root
// Link:     https://codeforces.com/contest/2173/problem/A
// Author:   nine19een
// Date:     2026-01-18

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << '\n';
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
