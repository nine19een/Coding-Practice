// Problem:  Luogu P3397 地毯
// Link:     https://www.luogu.com.cn/problem/P3397
// Author:   nine19een
// Date:     2025-08-17

#include<bits/stdc++.h>
using namespace std;

int n, m, x_1, y_1, x_2, y_2;
int carpet[1005][1005];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		carpet[x_1][y_1]++;
		carpet[x_1][y_2 + 1]--;
		carpet[x_2 + 1][y_1]--;
		carpet[x_2 + 1][y_2 + 1]++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			carpet[i][j] += carpet[i][j - 1] + carpet[i - 1][j] - carpet[i - 1][j - 1];
			cout << carpet[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
