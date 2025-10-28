// Problem:  Luogu P4414 [COCI 2006/2007 #2] ABC
// Link:     https://www.luogu.com.cn/problem/P4414
// Author:   nine19een
// Date:     2025-10-27

#include<stdio.h>

int num[5];

int max(int x, int y){
	return (x > y) ? x : y;
}

int min(int x, int y){
	return (x < y) ? x : y;
}

void swap(int *ptr_x, int *ptr_y){
	int z = *ptr_x;
	*ptr_x = *ptr_y;
	*ptr_y = z; 
}

void sort(){
	for(int i = 1; i <= 2; ++i){
		for(int j = 1; j <= 3 - i; ++j){
			if(num[j] > num[j + 1]){
				swap(&num[j], &num[j + 1]);
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &num[1], &num[2], &num[3]);
	getchar();
	sort();
	for(int i = 1; i <= 3; ++i){
		char c;
		scanf(" %c", &c);
		switch(c){
			case 'A':
				printf("%d ", num[1]);
				break;
			case 'B':
				printf("%d ", num[2]);
				break;
			case 'C':
				printf("%d ", num[3]);
				break;
		}		
	} 
	return 0;
}
