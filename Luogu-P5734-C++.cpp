// Problem:  Luogu P5734 【深基6.例6】文字处理软件
// Link:     https://www.luogu.com.cn/problem/P5734
// Author:   nine19een
// Date:     2025-07-16

#include <bits/stdc++.h>
using namespace std;
int const max1 = 1e4 + 5;
int const max2 = 1e2 + 5;
int q;
int deal_num[max2] = {0}, cut_idx[max2] = {0}, cut_len[max2] = {0}, insert_idx[max2] = {0};
char str[max1], back_str[max2][max2], insert_str[max2][max2], search_str[max2][max2];

void Deal_1(char str[],char back_str[]){
	strcat(str, back_str);
	cout << str << endl;
	return;
}
void Deal_2(char str[],int cut_idx,int cut_len){
	for(int j = 0; j < cut_len; j++){
		str[j] = str[cut_idx + j];
	}
	str[cut_len] = 0;
	cout << str << endl;
	return;
}
void Deal_3(char str[],int insert_idx,char insert_str[]){
	int insert_len = strlen(insert_str);
	int str_len = strlen(str);
	char store_str[max1];
	int store_len = str_len - insert_idx;
	for(int j = 0; j < store_len; j++){
		store_str[j] = str[insert_idx + j];
	}
	for(int j = 0; j < insert_len; j++){
		str[insert_idx + j] = insert_str[j];
	}
	for(int j = 0; j < store_len; j++){
		str[insert_idx + insert_len + j] = store_str[j];
	}
	str[insert_len + str_len] = 0;
	cout << str << endl;
	return;
}
void Deal_4(char str[],char search_str[]){
	int str_len = strlen(str);
	int search_len = strlen(search_str);
	for(int j = 0; j < str_len; j++){
		if(str[j] == search_str[0]){
			bool match = true;
			for(int k = 0; k < search_len; k++){
				if(str[j + k] != search_str[k]){
					match = false;
					break;
				}
			}
			if(match){
				cout << j << endl;
				return;
			}
			else{
				continue;
			}
		}
	}
	cout << -1 << endl;
	return;
}

int main(){
	memset(str, 0, sizeof(str));
	memset(back_str, 0, sizeof(back_str));
	memset(insert_str, 0, sizeof(insert_str));
	memset(search_str, 0, sizeof(search_str));	
	cin >> q >> str;
	for(int i = 1; i <= q; i++){
		cin >> deal_num[i];
		if(deal_num[i] == 1){
			cin >> back_str[i];
		}
		else if(deal_num[i] == 2){
			cin >> cut_idx[i] >> cut_len[i];
		}
		else if(deal_num[i] == 3){
			cin >> insert_idx[i] >> insert_str[i];
		}
		else if(deal_num[i] == 4){
			cin >> search_str[i];
		}				
	}
	for(int i = 1; i <= q; i++){
		if(deal_num[i] == 1){
			Deal_1(str, back_str[i]);
		}
		if(deal_num[i] == 2){
			Deal_2(str, cut_idx[i], cut_len[i]);
		}
		if(deal_num[i] == 3){
			Deal_3(str, insert_idx[i], insert_str[i]);
		}
		if(deal_num[i] == 4){
			Deal_4(str, search_str[i]);
		}
	}
	return 0;
}
