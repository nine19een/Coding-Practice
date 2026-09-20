// Problem:  AtCoder Beginner Contest 440 B - Trifecta
// Link:     https://atcoder.jp/contests/abc440/tasks/abc440_b
// Author:   nine19een
// Date:     2026-01-12

#include<bits/stdc++.h>
using namespace std;

struct Horse {
	int num, time;
};

Horse h[35];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i].time;
		h[i].num = i;
	}
	sort(h + 1, h + 1 + n, [](const Horse &a, const Horse &b) {
		return a.time < b.time;
	});
	cout << h[1].num << " " << h[2].num << " " << h[3].num;
	return 0;
}
