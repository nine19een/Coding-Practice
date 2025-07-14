// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P1957
// Author:   nine19een
// Date:     2025-07-15

#include <bits/stdc++.h>
using namespace std;

int n;
int ope[55] = {0};
char str[55][30], equ[55][30];
int Num1[55] = {0}, Num2[55] = {0};
int main(){
	memset(str, 0, sizeof(str));
	memset(equ, 0, sizeof(equ));
	cin >> n;
	cin.get();
	for(int i = 1; i <= n; i++){
		cin.getline(str[i], 30);
	}
	for(int i = 1; i <= n; i++){
		if(str[i][0] == 'a'){
			ope[i] = 1;
			char num1[10];
			char num2[10];
			memset(num1, 0, sizeof(num1));
			memset(num2, 0, sizeof(num2));
			int j = 1, n1 = 0, n2 = 0;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num1[n1] = str[i][j];
					n1++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			j++;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num2[n2] = str[i][j];
					n2++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			Num1[i] = stoi(num1);
			Num2[i] = stoi(num2);
		}
		else if(str[i][0] == 'b'){
			ope[i] = 2;
			char num1[10];
			char num2[10];
			memset(num1, 0, sizeof(num1));
			memset(num2, 0, sizeof(num2));			
			int j = 1, n1 = 0, n2 = 0;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num1[n1] = str[i][j];
					n1++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			j++;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num2[n2] = str[i][j];
					n2++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			Num1[i] = stoi(num1);
			Num2[i] = stoi(num2);
		}
		else if(str[i][0] == 'c'){
			ope[i] = 3;
			char num1[10];
			char num2[10];
			memset(num1, 0, sizeof(num1));
			memset(num2, 0, sizeof(num2));			
			int j = 1, n1 = 0, n2 = 0;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num1[n1] = str[i][j];
					n1++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			j++;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num2[n2] = str[i][j];
					n2++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			Num1[i] = stoi(num1);
			Num2[i] = stoi(num2);
		}
		else{
			ope[i] = ope[i - 1];
			char num1[10];
			char num2[10];
			memset(num1, 0, sizeof(num1));
			memset(num2, 0, sizeof(num2));			
			int j = 0, n1 = 0, n2 = 0;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num1[n1] = str[i][j];
					n1++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			j++;
			for(j; j < 30; j++){
				if(str[i][j] <= '9' && str[i][j] >= '0'){
					num2[n2] = str[i][j];
					n2++;
					if(!(str[i][j+1] <= '9' && str[i][j+1] >= '0')){
						break;
					}
				}
			}
			Num1[i] = stoi(num1);
			Num2[i] = stoi(num2);			
		}
	}
	for(int i = 1; i <= n; i++){
		if(ope[i] == 1){
			int sum_ = Num1[i] + Num2[i];
			sprintf(equ[i], "%d+%d=%d", Num1[i], Num2[i], sum_);
			int len = strlen(equ[i]);
			cout << equ[i] << endl << len << endl;	
		}
		if(ope[i] == 2){
			int sub_ = Num1[i] - Num2[i];
			sprintf(equ[i], "%d-%d=%d", Num1[i], Num2[i], sub_);
			int len = strlen(equ[i]);
			cout << equ[i] << endl << len << endl;	
		}
		if(ope[i] == 3){
			int mul_ = Num1[i] * Num2[i];
			sprintf(equ[i], "%d*%d=%d", Num1[i], Num2[i], mul_);
			int len = strlen(equ[i]);
			cout << equ[i] << endl << len << endl;	
		}
	}
	return 0;
}

