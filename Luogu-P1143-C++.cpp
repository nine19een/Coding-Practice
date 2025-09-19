// Problem:  Luogu P1143 进制转换
// Link:     https://www.luogu.com.cn/problem/P1143
// Author:   nine19een
// Date:     2025-07-21

#include<bits/stdc++.h>
using namespace std;
int n, m, Num10 = 0;
char str[100] = {0};
vector<char>str_num;

int to10(char c, int i, int len){
	int k = len - 1 - i, num;
	if(c == '0'){
		return 0;
	}
	else if(c == '1'){
		num = 1;
	}	
	else if(c == '2'){
		num = 2;
	}
	else if(c == '3'){
		num = 3;
	}
	else if(c == '4'){
		num = 4;
	}
	else if(c == '5'){
		num = 5;
	}
	else if(c == '6'){
		num = 6;
	}
	else if(c == '7'){
		num = 7;
	}
	else if(c == '8'){
		num = 8;
	}
	else if(c == '9'){
		num = 9;
	}
	else if(c == 'A'){
		num = 10;
	}
	else if(c == 'B'){
		num = 11;
	}
	else if(c == 'C'){
		num = 12;
	}
	else if(c == 'D'){
		num = 13;
	}
	else if(c == 'E'){
		num = 14;
	}
	else if(c == 'F'){
		num = 15;
	}
	if(k == 0){
		return num;
	}
	else {
		for(int j = 1; j <= k; j++){
			num *= n;
		}	
	}
	return num;
}

void from10(int &n10, vector<char>&sn){
	int rest = n10 % m;
	char rest_char;
	if(rest == 0){
		rest_char = '0';
	}
	else if(rest == 1){
		rest_char = '1';
	}
	else if(rest == 2){
		rest_char = '2';
	}
	else if(rest == 3){
		rest_char = '3';
	}
	else if(rest == 4){
		rest_char = '4';
	}
	else if(rest == 5){
		rest_char = '5';
	}
	else if(rest == 6){
		rest_char = '6';
	}
	else if(rest == 7){
		rest_char = '7';
	}
	else if(rest == 8){
		rest_char = '8';
	}
	else if(rest == 9){
		rest_char = '9';
	}
	else if(rest == 10){
		rest_char = 'A';
	}
	else if(rest == 11){
		rest_char = 'B';
	}
	else if(rest == 12){
		rest_char = 'C';
	}
	else if(rest == 13){
		rest_char = 'D';
	}
	else if(rest == 14){
		rest_char = 'E';
	}
	else if(rest == 15){
		rest_char = 'F';
	}
	sn.push_back(rest_char);
	n10 /= m;
	return;
}
int main(){
	cin >> n >> str >> m;
	int len = strlen(str);
	for(int i = len - 1; i >= 0; i--){
		Num10 += to10(str[i], i, len);
	}
	if(m == 10){
		cout << Num10;
		return 0;
	}
	str_num.reserve(100);
	for(int i = 1; i < 100; i++){
		from10(Num10, str_num);
		if(Num10 == 0){
			break;
		}
	}
	int strsize = str_num.size();
	for(int i = strsize - 1; i >= 0; i--){
		cout << str_num[i];
	}
	return 0;
}
