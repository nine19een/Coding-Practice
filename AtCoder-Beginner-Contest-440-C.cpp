// Problem:  AtCoder Beginner Contest 440 C - Striped Horse
// Link:     https://atcoder.jp/contests/abc438/tasks/abc440_c
// Author:   nine19een
// Date:     2026-01-13

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int t;

void op() {
	int n, w;
	cin >> n >> w;
	int W = 2 * w;
	vector<ll> v(W, 0);
	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		v[i % W] += c;
	}
	if (n <= w) {
		cout << 0 << '\n';
		return;
	}
	ll sum = 0;
	for (int i = 0; i < w; ++i) {
		sum += v[i];
	}
	int l = 0, r = w - 1;
	ll ans = sum;
	while (l < W) {
		sum -= v[l++];
		r = r == W - 1 ? 0 : r + 1;
		sum += v[r];
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		op();
	}
	return 0;
}
