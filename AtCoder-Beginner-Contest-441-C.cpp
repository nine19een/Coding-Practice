// Problem:  AtCoder Beginner Contest 441 C - Sake or Water
// Link:     https://atcoder.jp/contests/abc438/tasks/abc441_c
// Author:   nine19een
// Date:     2026-01-17

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;

ll n, k, x;
vector<ll> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	a.reserve(maxn);
	cin >> n >> k >> x;
	for (int i = 1; i <= n; ++i) {
		ll ai;
		cin >> ai;
		a.push_back(ai);
	}
	sort(a.begin(), a.end());
	int cnt_water = n - k;
	int cnt = cnt_water;
	while (cnt_water--) {
		a.pop_back();
	}
	ll sum = 0;
	sort(a.begin(), a.end(), greater<ll>());
	for (ll p: a) {
		sum += p;
		cnt++;
		if (sum >= x) {
			cout << cnt;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
