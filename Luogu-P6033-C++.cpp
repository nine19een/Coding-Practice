// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P6033
// Author:   nine19een
// Date:     2025-09-02

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e7 + 5, maxm = 1e5 + 5;

ll n, ans, cnt[maxm];
vector<ll> v;
queue<ll> q;

ll Sum(vector<ll> &v, queue<ll> &q, int &idx) {
	ll sum;
	if (q.empty()) {
		sum = v[idx];
		idx++;
	}
	else if (v.size() == idx) {
		sum = q.front();
		q.pop();
	}
	else {
		sum = min(v[idx], q.front());
		if (sum == v[idx]) {
			++idx;
		}
		else {
			q.pop();
		}
	}
	return sum;
}

void read(ll &x) {
	int sign = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			sign = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= sign;
}

int main(){
	v.reserve(maxn);
	read(n);
	for(int i = 1; i <= n; ++i){
		ll num;
		read(num);
		cnt[num]++;
	}
	for (int i = 1; i <= 100000; ++i) {
		for (int j = 1; j <= cnt[i]; ++j) {
			v.push_back(i);
		}
	}
	int idx = 0;
	while((v.size() - idx) + q.size() > 1){
		ll sum = Sum(v, q, idx);
		sum += Sum(v, q, idx);
		ans += sum;
		q.push(sum);
	}
	printf("%lld", ans);
	return 0;
}
