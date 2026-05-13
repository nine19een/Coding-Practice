// Problem:  Luogu P1908 逆序对
// Link:     https://www.luogu.com.cn/problem/P1908
// Author:   nine19een
// Date:     2025-08-12

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int>a, b;

int Lowbit(int x){
	return x & -x;
}

ll Sum(int x, ll arr[]){
	ll ansSUM = 0;
	for(int i = x; i != 0; i -= Lowbit(i)){
		ansSUM += arr[i];
	}
	return ansSUM;
}

void Update(int x, int add, int size, ll arr[]){
	for(int i = x; i <= size; i += Lowbit(i)){
		arr[i] += add;
	}
	return;
}

int main(){
	cin >> n;
	a.reserve(n + 5);
	b.reserve(n + 5);
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		a.push_back(num);
		b.push_back(num);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	int size = b.size();
	ll c[size + 5] = {0}, ans[size + 5] = {0};
	int cnt = 0;
	for(int p : a){
		cnt++;
		int idx = lower_bound(b.begin(), b.end(), p) - b.begin() + 1;
		Update(idx, 1, size, c);
		Update(idx, cnt - Sum(idx, c), size, ans);
	}
	cout << Sum(size, ans);
	return 0;
}
