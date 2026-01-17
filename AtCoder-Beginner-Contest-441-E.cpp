// Problem:  AtCoder Beginner Contest 441 E - A > B substring
// Link:     https://atcoder.jp/contests/abc438/tasks/abc441_e
// Author:   nine19een
// Date:     2026-01-17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;

ll n, bit[maxn], ans;
string s;

ll lowbit(ll x) {
	return x & -x;
}

void update(ll idx, ll val, ll limit) {
	for (ll i = idx; i <= limit; i += lowbit(i)) {
		bit[i] += val;
	}
}

int query(ll idx) {
	int sum = 0;
	for (ll i = idx; i; i -= lowbit(i)) {
		sum += bit[i];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	ll offset = n + 1;
	ll limit = 2 * n + 5;
	ll cur_sum = 0;
	update(offset, 1, limit);
	for (char c: s) {
		if (c == 'A') {
			cur_sum++;
		} else if (c == 'B') {
			cur_sum--;
		}
		ans += query(cur_sum + offset - 1);
		update(cur_sum + offset, 1, limit);
	}
	cout << ans;
	return 0;
}
