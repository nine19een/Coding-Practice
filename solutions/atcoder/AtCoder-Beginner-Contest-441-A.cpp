// Problem:  AtCoder Beginner Contest 441 A - Black Square
// Link:     https://atcoder.jp/contests/abc441/tasks/abc441_a
// Author:   nine19een
// Date:     2026-01-17

#include<bits/stdc++.h>
using namespace std;

int p, q, x, y;

int main() {
	cin >> p >> q >> x >> y;
	if (x >= p && x < p + 100 && y >= q && y < q + 100) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}
