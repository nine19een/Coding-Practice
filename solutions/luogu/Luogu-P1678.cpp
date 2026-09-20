// Problem:  Luogu P1678 烦恼的高考志愿
// Link:     https://www.luogu.com.cn/problem/P1678
// Author:   nine19een
// Date:     2025-07-16

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
int m, n; 
int sch[maxn], stu[maxn], dissatisfaction[maxn];
long long sum = 0;
int solve(int i){
	if(stu[i] <= sch[0] || stu[i] >= sch[m-1]){
		return min(abs(sch[0] - stu[i]), abs(sch[m-1] - stu[i]));
	}
	else{
		int left = 0, right = m - 1;
		while(left <= right){
			int middle = (left + right) / 2;
			if(stu[i] == sch[middle]){
				return 0;
			}
			else if(stu[i] < sch[middle]){
				right = middle;
			}
			else if(stu[i] > sch[middle]){
				left = middle;
			}
			if(right == left + 1){
				return min(abs(stu[i] - sch[left]), abs(stu[i] - sch[right]));
			}
		}
	}
}

int main(){
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		cin >> sch[i];
	}
	sort(sch, sch + m);
	for(int i = 0; i < n; i++){
		cin >> stu[i];
		dissatisfaction[i] = solve(i);
	}
	for(int i = 0; i < n; i++){
		sum += dissatisfaction[i];
	}
	cout << sum;
	return 0;	
}
