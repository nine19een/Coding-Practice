// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P12163
// Author:   nine19een
// Date:     2025-08-23

#include<bits/stdc++.h>
using namespace std;

int ans;

void F(int num){
	int cnt[10] = {0}, r;
	for(int i = 1; i <= 9; ++i){
		r = num % 10;
		if(r == 2){
			cnt[2]++;
		}
		else if(r == 5){
			cnt[5]++;
		}
		else if(r == 0){
			cnt[0]++;
		}
		if(num < 10){
			break;
		}
		num = (num - r) / 10;
	}
	if(cnt[2] >= 2 && cnt[0] && cnt[5]){
		ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	for(int i = 1; i <= 20250412; ++i){
		F(i);
	}
	cout << ans;
	return 0;
}
