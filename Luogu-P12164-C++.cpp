// Problem:  Luogu P12164 [蓝桥杯 2025 省 C/Python A] 2025 图形
// Link:     https://www.luogu.com.cn/problem/P12164
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int h, w;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> h >> w;
	int a[] = {2, 0, 2, 5};
	int cnt, start = 0;
	for(int i = 1; i <= h; ++i){
		cnt = start;
		for(int j = 1; j <= w; ++j){
			cout << a[cnt++];
			if(cnt == 4){
				cnt = 0;
			}
		}
		cout << '\n';
		start++;
		if(start == 4){
			start = 0;
		}
	}
	return 0;
}
