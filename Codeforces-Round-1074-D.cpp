// Problem:  Codeforces Round 1074 D - OutOfMemoryError
// Link:     https://codeforces.com/contest/2173/problem/D
// Author:   nine19een
// Date:     2026-01-18

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
	ll n, m, h;
	cin >> n >> m >> h;
	vector<ll> a(n), cur(n);
	stack<int> history;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cur = a;
	for (int i = 1; i <= m; ++i) {
		ll b, c;
		cin >> b >> c;
		b--;
		cur[b] += c;
		history.push(b);
		if (cur[b] > h) {
			while (!history.empty()) {
				int top = history.top();
				cur[top] = a[top];
				history.pop();
			}
		}
	}
	for (ll p: cur) {
		cout << p << " ";
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
