// Problem:  Codeforces Round 1057 C. Symmetrical Polygons
// Link:     https://codeforces.com/contest/2153/problem/C
// Author:   nine19een
// Date:     2025-10-11

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

bool isEven(ll x){
	return !(x & 1);
}

ll Ans(int size_s, ll cnt_side, ll side, vector<ll>& single_num) {
	ll ans = 0;
	if(!size_s){
		ans = (cnt_side <= 1) ? 0 : side * 2;
	}
	else{
		if(!side){
			ans = 0;
		}
		else{
			sort(single_num.begin(), single_num.end(), greater<ll>());
			auto it = single_num.begin();
			for (it; it != prev(single_num.end()); ++it) {
				if((*it - *next(it)) < side * 2){
					ans = side * 2 + (*it) + (*next(it));
					return ans;
				}
			}
			if((*it) < 2 * side){
				ans = 2 * side + (*it);
				return ans;
			}
			ans = (cnt_side == 1) ? 0 : 2 * side;
		}
	}
	return ans;
}

void op(){
	int n;
	ll side = 0, cnt_side = 0;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		a[i] = num, b[i] = num;
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	int size = b.size();
	vector<ll> cnt(size, 0);
	for(ll p : a){
		int idx = lower_bound(b.begin(), b.end(), p) - b.begin();
		cnt[idx]++;
	}
	vector<ll> single_num;
	single_num.reserve(size);
	for(int i = 0; i < size; ++i){
		if(cnt[i] >= 2){
			if(isEven(cnt[i])){
				side += b[i] * cnt[i] / 2;
				cnt_side += cnt[i] / 2;
			}
			else{
				side += b[i] * (cnt[i] - 1) / 2;
				cnt_side += (cnt[i] - 1) / 2;
				single_num.push_back(b[i]);
			}
		}
		else if(cnt[i] == 1){
			single_num.push_back(b[i]);
		}
	}
	int size_s = single_num.size();
	cout << Ans(size_s, cnt_side, side, single_num) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		op();
	}
	return 0;
}
