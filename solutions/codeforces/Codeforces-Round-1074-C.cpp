// Problem:  Codeforces Round 1074 C - Shifted MEX
// Link:     https://codeforces.com/contest/2173/problem/C
// Author:   nine19een
// Date:     2026-01-18

#include<bits/stdc++.h>
using namespace std;

int t;

void op() {
	int n, cnt = 1, last_a, max_cnt = 1;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	last_a = a.front();
	for (int p: a) {
		if (p == last_a + 1) {
			cnt++;
		} else {
			cnt = 1;
		}
		max_cnt = max(max_cnt, cnt);
		last_a = p;
	}
	cout << max_cnt << '\n';
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
