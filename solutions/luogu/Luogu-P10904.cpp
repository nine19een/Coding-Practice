// Problem:  Luogu P10904 [蓝桥杯 2024 省 C] 挖矿
// Link:     https://www.luogu.com.cn/problem/P10904
// Author:   nine19een
// Date:     2025-09-16

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 5;

int n, m, ans, cnt_0;

int distance(int l, int r){
	if(l <= 0 && r >= 0){
		return (abs(l) >= r) ? 2 * r + abs(l) : 2 * abs(l) + r;
	}
	else if(r <= 0){
		return abs(l);
	}
	else if(l >= 0){
		return r;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == 0){
			cnt_0 = 1;
		}
	}
	sort(a.begin(), a.end());	
	if(a[0] >= 0){
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] > m){
				break;
			}
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	if(a.back() <= 0){
		int cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			if(abs(a[i]) > m){
				break;
			}
			cnt++;
		}
		cout << cnt;
		return 0;		
	}
	int l = 0, r = 0;
	int cnt = 1;
	while(1){
		if(r >= n){
			break;
		}
		if(distance(a[l], a[r]) <= m){
			ans = max(ans, cnt);
			r++;
			cnt++;
			continue;
		}
		else{
			cnt--;
			l++;
			if(l > r){
				r++;
				cnt++;
			}
			continue;
		}
	}
	cout << ans;
	return 0;
}
