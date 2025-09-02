// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1090
// Author:   nine19een
// Date:     2025-09-02

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e4 + 5;
int n, ans;
priority_queue<int, vector<int>, greater<int>>pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int num;
		cin >> num;
		pq.push(num);
	}
	while(!pq.empty()){
		if(pq.size() == 1){
			cout << ans;
			return 0;
		}
		int sum = pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		ans += sum;
	}
	return 0;
}
