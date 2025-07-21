// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1067
// Author:   nine19een
// Date:     2025-07-22

#include<bits/stdc++.h>
using namespace std;
int n;
int coe[105] = {0};

void multinomial(int i){
	if(coe[i] == 0){
		return;
	}
	if(coe[i] > 0){
		if(i == 0){
			cout << "+" << coe[i];
			return;
		}
		if(coe[i] == 1){
			if(i == n){
				cout << "x^" << i;
				return;
			}
			if(i == 1){
				cout << "+x";
				return;
			}
			cout << "+x^" << i;
			return; 			
		}
		if(i == n){
			cout << coe[i] << "x^" << i;
			return;
		}
		if(i == 1){
			cout << "+" << coe[i] << "x";
			return;
		}
		cout << "+" << coe[i] << "x^" << i; 
		return;
	} 
	if(coe[i] < 0){
		if(i == 0){
			cout << coe[i];
			return;
		}
		if(coe[i] == -1){
			if(i == 1){
				cout << "-x";
				return;
			}
			cout << "-x^" << i;
			return; 			
		}		
		if(i == n){
			cout << coe[i] << "x^" << i;
			return;
		}
		if(i == 1){
			cout << coe[i] << "x";
			return;
		}
		cout << coe[i] << "x^" << i; 	
		return;	
	}
}

int main(){
	cin >> n;
	for(int i = n; i >= 0; i--){
		cin >> coe[i];
	}
	if(n == 0){
		cout << coe[0];
		return 0;
	}
	for(int i = n; i >= 0; i--){
		multinomial(i);
	}	
	return 0;
} 
