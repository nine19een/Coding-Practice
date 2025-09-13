// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P10425
// Author:   nine19een
// Date:     2025-09-14

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string d;
vector<ll> int_part, double_part;

void Carry(vector<ll>& inte, vector<ll>& dble){
	int carry_1 = 0;
	for(auto it = dble.begin(); it != dble.end(); ++it){
		*it = (*it << 1) + carry_1;
		carry_1 = *it >= 10;
		*it %= 10;
	}
	for(auto it = inte.begin(); it != inte.end(); ++it){
		*it = (*it << 1) + carry_1;
		carry_1 = *it >= 10;
		*it %= 10;
	}
	if(carry_1){
		inte.push_back(1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int_part.reserve(1030);
	double_part.reserve(1030);
	cin >> n >> d;
	string::iterator it_point;
	for(auto it = d.begin(); it != d.end(); ++it){
		if(*it == '.'){
			it_point = it;
			break;
		}
		int_part.push_back(*it - '0');
	}
	for(++it_point; it_point != d.end(); ++it_point){
		double_part.push_back(*it_point - '0');
	}
	reverse(int_part.begin(), int_part.end());
	reverse(double_part.begin(), double_part.end());
	while(n--){
		Carry(int_part, double_part);
	}
	int carry_1 = 0;
	carry_1 = double_part.back() >= 5;
	for(auto it = int_part.begin(); it != int_part.end(); ++it){
		if(carry_1){
			(*it)++;
			carry_1 = *it >= 10;
			*it %= 10;
		}
	}
	if(carry_1){
		int_part.push_back(1);
	}
	reverse(int_part.begin(), int_part.end());
	reverse(double_part.begin(), double_part.end());
	for(ll p : int_part){
		cout << p;
	}
	return 0;
}
