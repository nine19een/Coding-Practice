// Problem:  AtCoder Beginner Contest 442 A - Count .
// Link:     https://atcoder.jp/contests/abc438/tasks/abc442_a
// Author:   nine19een
// Date:     2026-01-24

#include<bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main() {
	cin >> s;
	for (char c: s) {
		if (c == 'i' || c == 'j') {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
