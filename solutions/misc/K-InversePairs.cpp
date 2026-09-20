// Problem:  逆序K倍对
// Link:     https://www.nine19een.com/2025/10/13/K-InversePairs/
// Author:   nine19een
// Date:     2025-10-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll ans;
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
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	a.reserve(n + 5);
	b.reserve(2 * n + 5);
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		a.push_back(num);
		b.push_back(num);
		b.push_back(k * num);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	int size = b.size();
	ll c[size + 5] = {0};
	ll cnt = 0;
	for(int p : a){
		cnt++;
		int idx = lower_bound(b.begin(), b.end(), p) - b.begin() + 1;
		int idx2 = lower_bound(b.begin(), b.end(), p * k) - b.begin() + 1;
		Update(idx, 1, size, c);
		ans += cnt - Sum(idx2, c);
	}
	cout << ans;
	return 0;
}
