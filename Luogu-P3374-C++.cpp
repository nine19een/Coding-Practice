// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P3374
// Author:   nine19een
// Date:     2025-08-12

#include <bits/stdc++.h>
using namespace std;
int const maxn = 5e5 + 5;

int n, m;
int a[maxn], c[maxn];

int Lowbit(int num){
	return num & (num ^ (num - 1));
}

int Query(int idx){
	int ans = 0;
	for(int i = idx; i != 0; i -= Lowbit(i)){
		ans += c[i];
	}
	return ans;
}

void Change(int n){
	int idx, add;
	cin >> idx >> add;
	for(int i = idx; i <= n; i += Lowbit(i)){
		c[i] += add;
	}
	return;
}

void Sum(int n){
	int x, y;
	cin >> x >> y;
	cout << Query(y) - Query(x - 1) << endl;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i] + Query(i - 1) - Query(i - Lowbit(i));
	}
	for(int i = 1; i <= m; i++){
		int exe;
		cin >> exe;
		if(exe == 1){
			Change(n);
		}
		else if(exe == 2){
			Sum(n);
		}
	}
	return 0;
}
