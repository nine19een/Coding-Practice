// Problem:  AtCoder Beginner Contest 439 C - 2026
// Link:     https://atcoder.jp/contests/abc439/tasks/abc439_c
// Author:   nine19een
// Date:     2026-01-04

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e7 + 5;

int n, cnt[maxn];
vector<int> ans;

void findGood(int n){
	int k = sqrt(n - 1);
	for(int i = 2; i <= k; ++i){
		for(int j = 1; j < i; ++j){
			int sum = j * j + i * i;
			if(sum > n){
				break;
			}
			cnt[sum]++;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(cnt[i] == 1){
			ans.push_back(i);
		}
	}
}

int main(){
	ans.reserve(maxn);
	cin >> n;
	findGood(n);
	int ans_size = ans.size();
	if(!ans_size){
		cout << 0;
		return 0;
	}
	cout << ans_size << '\n';
	for(int p: ans){
		cout << p << " ";
	}
	return 0;
}
