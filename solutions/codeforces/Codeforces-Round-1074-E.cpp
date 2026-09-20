// Problem:  Codeforces Round 1074 E - The Robotic Rush
// Link:     https://codeforces.com/contest/2173/problem/E
// Author:   nine19een
// Date:     2026-01-19

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18, maxn = 2e5 + 5;

struct Death {
	ll left, right;
};

int t;

void op() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(m);
	vector<Death> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		if (it == b.end()) {
			d[i].left = *prev(it);
			d[i].right = INF;
			continue;
		}
		if (it == b.begin()) {
			d[i].left = -INF;
			d[i].right = *it;
			continue;
		}
		d[i].left = *prev(it);
		d[i].right = *it;
	}
	int cur_idx = 0, minl = 0, maxr = 0;
	vector<int> l_1st(k + 5, -1), r_1st(k + 5, -1);
	for (int i = 1; i <= k; ++i) {
		char c;
		cin >> c;
		if (c == 'L') {
			cur_idx--;
		} else {
			cur_idx++;
		}
		if (cur_idx < 0) {
			if (l_1st[abs(cur_idx)] == -1) {
				l_1st[abs(cur_idx)] = i;
			}
		}
		if (cur_idx > 0) {
			if (r_1st[cur_idx] == -1) {
				r_1st[cur_idx] = i;
			}
		}
		minl = min(cur_idx, minl);
		maxr = max(cur_idx, maxr);
	}
	vector<int> cnt(k, 0);
	for (int i = 0; i < n; ++i) {
		ll l = INF, r = INF;
		if (a[i] + minl <= d[i].left) {
			l = l_1st[a[i] - d[i].left];
		}
		if (a[i] + maxr >= d[i].right) {
			r = r_1st[d[i].right - a[i]];
		}
		ll first = min(l, r);
		if (first != INF) {
			cnt[first - 1]++;
		}
	}
	int tot = n;
	for (int i = 0; i < k; ++i) {
		tot -= cnt[i];
		cout << tot << " ";
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
