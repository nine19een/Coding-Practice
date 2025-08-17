// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P2357
// Author:   nine19een
// Date:     2025-08-17

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const maxn = 2e5 + 5;

ll n, f, num, l, r, k, ans;
ll a[maxn], diff[maxn], c[maxn], cxc[maxn];

ll Lowbit(ll x){
	return x & -x;
}

ll Sum(ll x, ll arr[]){
	ans = 0;
	for(ll i = x; i != 0; i -= Lowbit(i)){
		ans += arr[i];
	}
	return ans;
}

void Change1(ll x, ll y, ll add){
	for(ll i = x; i <= n; i += Lowbit(i)){
		c[i] += add;
	}
	for(ll i = y + 1; i <= n; i += Lowbit(i)){
		c[i] -= add;
	}
	return;
}

void Change2(ll x, ll y, ll add){
	for(ll i = x; i <= n; i += Lowbit(i)){
		cxc[i] += add * x;
	}
	for(ll i = y + 1; i <= n; i += Lowbit(i)){
		cxc[i] -= add * (y + 1);
	}
	return;
}

void Execute_(ll num){
	if(num == 1){
		cin >> l >> r >> k;
		Change1(l, r, k);
		Change2(l, r, k);
	}
	else if(num == 2){
		cin >> k;
		Change1(1, 1, k);
		Change2(1, 1, k);
	}
	else if(num == 3){
		cin >> k;
		Change1(1, 1, -k);
		Change2(1, 1, -k);
	}
	else if(num == 4){
		cin >> l >> r;
		ans = Sum(r, c) * (r + 1) - Sum(r, cxc) - (Sum(l - 1, c) * l - Sum(l - 1, cxc));
		cout << ans << endl;
	}
	else if(num == 5){
		cout << c[1] << endl;
	}
	return;
}

int main(){
	cin >> n >> f;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
		c[i] = diff[i] + Sum(i - 1, c) - Sum(i - Lowbit(i), c);
		cxc[i] = diff[i] * i + Sum(i - 1, cxc) - Sum(i - Lowbit(i), cxc);
	}
	for(ll i = 1; i <= f; i++){
		cin >> num;
		Execute_(num);
	}
	return 0;
}
