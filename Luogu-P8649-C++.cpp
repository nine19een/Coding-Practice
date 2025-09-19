// Problem:  Luogu P8649 [蓝桥杯 2017 省 B] k 倍区间
// Link:     https://www.luogu.com.cn/problem/P8649
// Author:   nine19een
// Date:     2025-09-12

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e5 + 5;
int n, k;
ll a[maxn], pre[maxn], cnt[maxn], ans;

ll CNT(ll x){
	return x * (x - 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> k;
	cnt[0]++;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		cnt[pre[i] % k]++;
	}
	for(int i = 0; i < k; ++i){
		ans += CNT(cnt[i]);
	}
	cout << ans;
	return 0;
}
