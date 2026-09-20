// Problem:  Codeforces Round 1017 D. Tung Tung Sahur
// Link:     https://codeforces.com/contest/2094/problem/D
// Author:   nine19een
// Date:     2025-08-08

#include <bits/stdc++.h>
using namespace std;
struct Check{
	char lr;
	int cnt;
};
int const maxn = 1e4 + 5, maxm = 2e5 + 5;
int t;

void judge(vector<Check>&R, vector<Check>&H){
	int sizeR = R.size(), sizeH = H.size();
	if(sizeR != sizeH){
		cout << "NO" << endl;
		return;
	}
	for(int i = 0; i <= sizeR - 1; i++){
		if(R[i].lr != H[i].lr){
			cout << "NO" << endl;
			return;
		}
		else{
			if(R[i].cnt <= H[i].cnt && 2 * R[i].cnt >= H[i].cnt){
				continue;
			}
			else{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		vector<Check>R;
		vector<Check>H;
		char real[maxm] = {0}, heard[maxm] = {0};
		cin >> real >> heard;
		int cnt_l = 0, cnt_r = 0;
		for(int j = 0; j <= maxm; j++){
			if(real[j] == 0){
				break;
			}
			if(real[j] == 'L'){
				cnt_l++;
				if(real[j + 1] == 'L'){
					continue;
				}
				if(real[j + 1] != 'L'){
					Check rr = {'L', cnt_l};
					R.push_back(rr);
					cnt_l = 0;
					continue;
				}
			}
			if(real[j] == 'R'){
				cnt_r++;
				if(real[j + 1] == 'R'){
					continue;
				}
				if(real[j + 1] != 'R'){
					Check rr = {'R', cnt_r};
					R.push_back(rr);
					cnt_r = 0;
					continue;
				}
			}
		}
		for(int j = 0; j <= maxm; j++){
			if(heard[j] == 0){
				break;
			}
			if(heard[j] == 'L'){
				cnt_l++;
				if(heard[j + 1] == 'L'){
					continue;
				}
				if(heard[j + 1] != 'L'){
					Check hh = {'L', cnt_l};
					H.push_back(hh);
					cnt_l = 0;
					continue;
				}
			}
			if(heard[j] == 'R'){
				cnt_r++;
				if(heard[j + 1] == 'R'){
					continue;
				}
				if(heard[j + 1] != 'R'){
					Check hh = {'R', cnt_r};
					H.push_back(hh);
					cnt_r = 0;
					continue;
				}
			}
		}
		judge(R, H);
		R.clear();
		H.clear();
	}
	return 0;
}
