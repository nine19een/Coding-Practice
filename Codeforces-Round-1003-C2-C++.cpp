// Problem:  Codeforces Round 1003 C2. Skibidus and Fanum Tax (hard version)
// Link:     https://codeforces.com/contest/2065/problem/C2
// Author:   nine19een
// Date:     2025-07-24

#include <bits/stdc++.h>
using namespace std;
int const max1 = 2e5 + 5;
int const max2 = 1e4 + 5;
int const inf = 1e9 + 5;
int t;
vector<int>n;
vector<int>m;
int N[max2], M[max2];

int FINDmin(int ai, int n, vector<int>&m, int M, int last_min_ai){
	int left = 0;
	int right = M;
	while(left < right){
		int middle = (left + right) / 2;
		if(m[middle] - n == last_min_ai){
			return last_min_ai;
		}
		if(m[middle] - n > last_min_ai){
			ai = min((m[middle] - n), ai);
			right = middle;
		}
		else if(m[middle] - n < last_min_ai){
			left = middle + 1;
		}
	}
	if(ai == inf){
		return n;
	}
	return ai;
}

void tax(vector<int>&n, vector<int>&m, int N, int M){
	if(N == 1){
		cout << "YES" << endl;
		return;
	}
	int min_ai[N + 5];
	sort(m.begin(), m.end());
	for(int i = 0; i < N; i++){
		if(i == 0){
			min_ai[0] = min(m[0] - n[i], n[i]);
			continue;
		}
		else{
			int ai = inf;
			ai = FINDmin(ai, n[i], m, M, min_ai[i - 1]);
			if(n[i] < ai){
				if(ai < min_ai[i - 1]){
					cout << "NO" << endl;		
					return;
				}
				else if(n[i] < min_ai[i - 1] && min_ai[i - 1] <= ai){
					min_ai[i] = ai;		
					continue;
				}
				else if(min_ai[i - 1] <= n[i]){
					min_ai[i] = n[i];
					continue;
				}
			}
			if(ai < min_ai[i - 1]){
				cout << "NO" << endl;
				return;
			}	
			min_ai[i] = ai;
		}
	}
	cout << "YES" << endl;
	return;
}
int main(){
	n.reserve(max1);
	m.reserve(max1);
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> N[i] >> M[i];
		for(int j = 1; j <= N[i]; j++){
			int nn;
			cin >> nn;
			n.push_back(nn);
		}
		for(int k = 1; k <= M[i]; k++){
			int mm;
			cin >> mm;
			m.push_back(mm);
		}
		tax(n, m, N[i], M[i]);
		n.clear();
		m.clear();
	}
	return 0;
}

