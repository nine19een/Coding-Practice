// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P3368
// Author:   nine19een
// Date:     2025-08-12

#include <bits/stdc++.h>
using namespace std;
int const maxn = 5e5 + 5;

int n, m;
int a[maxn], b[maxn], c[maxn];

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
	int idx1, idx2, add;
	cin >> idx1 >> idx2 >> add;
	for(int i = idx1; i <= n; i += Lowbit(i)){
		c[i] += add;
	}
	for(int i = idx2 + 1; i <= n; i += Lowbit(i)){
		c[i] -= add;
	}
	return;
}

void Search(int n){
	int idx;
	cin >> idx;
	cout << Query(idx) << endl;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
		c[i] = b[i] + Query(i - 1) - Query(i - Lowbit(i));
	}
	int exe;
	for(int i = 1; i <= m; i++){
		cin >> exe;
		if(exe == 1){
			Change(n);
		}
		else if(exe == 2){
			Search(n);
		}
	}
	return 0;
}
