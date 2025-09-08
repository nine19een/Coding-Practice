// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P13876
// Author:   nine19een
// Date:     2025-09-08

#include<bits/stdc++.h>
using namespace std;

long long cnt;

bool isLEAPyear(int year){
	if(((year & 3) == 0 && (year % 100 != 0)) || year % 400 == 0){
		return true;
	}
	return false;
}

bool special(int y, int m, int d){
	if((y % m == 0) && (y % d == 0)){
		return true;
	}
	return false;
}

int main(){
	for(int y = 2000; y <= 1999999; ++y){
		for(int m = 1; m <= 12; ++m){
			switch(m){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:{
					for(int d = 1; d <= 31; ++d){
						if(special(y, m, d)){
							cnt++;
						}
					}
					break;
				}
				case 4:
				case 6:
				case 9:
				case 11:{
					for(int d = 1; d <= 30; ++d){
						if(special(y, m, d)){
							cnt++;
						}
					}						
					break;
				}
				case 2:{
					if(!isLEAPyear(y)){
						for(int d = 1; d <= 28; ++d){
							if(special(y, m, d)){
								cnt++;
							}
						}
					}
					else{
						for(int d = 1; d <= 29; ++d){
							if(special(y, m, d)){
								cnt++;
							}
						}
					}						
					break;
				}
			}
		}	
	}
	cout << cnt + 1;
	return 0;
}
