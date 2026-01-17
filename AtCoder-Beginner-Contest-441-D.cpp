// Problem:  AtCoder Beginner Contest 441 D - Paid Walk
// Link:     https://atcoder.jp/contests/abc438/tasks/abc441_d
// Author:   nine19een
// Date:     2026-01-17

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

struct Node {
	ll dis, cnt, u;
};

struct Side {
	ll v, w;
};

ll n, m, l, s, t;
vector<Side> side[maxn];
set<ll> ans;

void BFS() {
	queue<Node> q;
	q.push({0, 0, 1});
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		if (f.dis >= s && f.dis <= t && f.cnt == l) {
			ans.insert(f.u);
			continue;
		}
		for (auto sd: side[f.u]) {
			ll new_dis = f.dis + sd.w;
			if (new_dis <= t && f.cnt < l) {
				q.push({new_dis, f.cnt + 1, sd.v});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> l >> s >> t;
	for (int i = 1; i <= m; ++i) {
		ll u, v, c;
		cin >> u >> v >> c;
		side[u].push_back({v, c});
	}
	BFS();
	for (ll p: ans) {
		cout << p << " ";
	}
	return 0;
}
