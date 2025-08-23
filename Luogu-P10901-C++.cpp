// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P10901
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 2e5 + 5, maxm = 3.6e6 + 5;

struct closeANDnum{
	int close, num;
};
int n;
vector<closeANDnum>a;

ll HowManyClose(int x){
	ll ans = 0;
	int r;
	for(int i = 1; i <= 9; ++i){
		int ten = 10;
		r = x % ten;
		if(r == 0 || r == 4 || r == 6 || r == 9){
			ans += 1;
		}
		else if(r == 8){
			ans += 2;
		}
		x -= r;
		x /= 10;
		if(x <= 0){
			return ans;
		} 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	closeANDnum c;
	for(int i = 1; i <= n; ++i){
		cin >> c.num;
		c.close = HowManyClose(c.num);
		a.push_back(c);
	}
	sort(a.begin(), a.end(), [](const closeANDnum& left, const closeANDnum& right){
		if(left.close != right.close){
			return left.close < right.close;
		}
		return left.num < right.num;
	});
	for(auto p : a){
		cout << p.num << " ";
	}
	return 0;
}
