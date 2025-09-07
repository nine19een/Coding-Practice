// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P13887
// Author:   nine19een
// Date:     2025-09-07

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e5 + 5;
ll n, A, B, C, a[maxn], b[maxn], c[maxn], cnt_a, cnt_b, cnt_c;
vector<ll>val_a, val_b, val_c;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 3; ++i){
		for(int j = 1; j <= n; ++j){
			switch(i){
				case 1:{
					cin >> a[j];
					break;
				}
				case 2:{
					cin >> b[j];
					break;
				}
				case 3:{
					cin >> c[j];
					break;
				}	
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		val_a.push_back(a[i] - b[i] - c[i]);
		val_b.push_back(b[i] - a[i] - c[i]);
		val_c.push_back(c[i] - a[i] - b[i]);
	}
	sort(val_a.begin(), val_a.end(), greater<ll>());
	sort(val_b.begin(), val_b.end(), greater<ll>());
	sort(val_c.begin(), val_c.end(), greater<ll>());
	ll ans = 0;
	for(ll p : val_a){
		A += p;
		if(A <= 0){
			break;
		}
		cnt_a++;
	}
	ans = max(ans, cnt_a);
	for(ll p : val_b){
		B += p;
		if(B <= 0){
			break;
		}
		cnt_b++;
	}
	ans = max(ans, cnt_b);
	for(ll p : val_c){
		C += p;
		if(C <= 0){
			break;
		}
		cnt_c++;
	}
	ans = max(ans, cnt_c);
	if(ans == 0){
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}
