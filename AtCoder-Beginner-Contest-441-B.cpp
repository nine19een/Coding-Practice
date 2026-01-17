// Problem:  AtCoder Beginner Contest 441 B - Two Languages
// Link:     https://atcoder.jp/contests/abc438/tasks/abc441_b
// Author:   nine19een
// Date:     2026-01-17

#include<bits/stdc++.h>
using namespace std;

int n, m, q;
unordered_map<char, int> s, t;

void Cmp(string &w) {
	bool is_s = true, is_t = true;
	for (char c: w) {
		if (!s.count(c)) {
			is_s = false;
		}
		if (!t.count(c)) {
			is_t = false;
		}
	}
	if (is_s && !is_t) {
		cout << "Takahashi";
	} else if (!is_s && is_t) {
		cout << "Aoki";
	} else {
		cout << "Unknown";
	}
	cout << '\n';
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		s[c]++;
	}
	for (int i = 1; i <= m; ++i) {
		char c;
		cin >> c;
		t[c]++;
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		string w;
		cin >> w;
		Cmp(w);
	}
	return 0;
}
