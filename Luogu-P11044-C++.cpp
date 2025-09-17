// Problem:  洛谷 P11044 [蓝桥杯 2024 省 Java B] 食堂
// Link:     https://www.luogu.com.cn/problem/P11044
// Author:   nine19een
// Date:     2025-09-14

#include<bits/stdc++.h>
using namespace std;

int q, a2, a3, a4, b4, b6;

int Greed(int a2, int a3, int a4, int b4, int b6){
	int ans = 0;
	while(a4 && b4){
		ans += 4;
		a4--;
		b4--;
	}
	while(a3 >= 2 && b6){
		ans += 6;
		a3 -= 2;
		b6--;
	}
	while(a4 && a2 && b6){
		ans += 6;
		a4--;
		a2--;
		b6--;
	}
	while(a2 >= 3 && b6){
		ans += 6;
		a2 -= 3;
		b6--;
	}
	while(a2 >= 2 && b4){
		ans += 4;
		a2 -= 2;
		b4--;
	}
	while(a3 && b4){
		ans += 3;
		a3--;
		b4--;
	}
	while(a3 && a2 && b6){
		ans += 5;
		a3--;
		a2--;
		b6--;
	}
	while(a4 && b6){
		ans += 4;
		a4--;
		b6--;
	}
	while(a2 == 2 && b6){
		ans += 4;
		a2 = 0;
		b6--;
	}
	while(a2 && b4){
		ans += 2;
		a2--;
		b4--;
	}
	while(a3 && b6){
		ans += 3;
		a3--;
		b6--;
	}
	while(a2 && b6){
		ans += 2;
		a2--;
		b6--;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> q;
	while(q--){
		cin >> a2 >> a3 >> a4 >> b4 >> b6;
		cout << Greed(a2, a3, a4, b4, b6) << '\n';
	}
	return 0;
}  
