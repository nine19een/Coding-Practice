// Problem:  Luogu B2112 石头剪子布
// Link:     https://www.luogu.com.cn/problem/B2112
// Author:   nine19een
// Date:     2025-11-04

#include<stdio.h>
#define maxn 105

int n;
char c1[maxn], c2[maxn];

void match(char s[], char c[], int idx){
	if(s[0] == 'P'){
		c[idx] = 'P';
	}
	else if(s[0] == 'S'){
		c[idx] = 'S';

	}
	else if(s[0] == 'R'){
		c[idx] = 'R';
	}
}

void input(int idx){
	char s1[10], s2[10];
	scanf(" %s %s", s1, s2);
	match(s1, c1, idx);
	match(s2, c2, idx);
}

void compete(){
	for(int i = 1; i <= n; ++i){
		if(c1[i] == c2[i]){
			printf("Tie\n");
		}
		else if((c1[i] == 'P' && c2[i] == 'R') || (c1[i] == 'R' && c2[i] == 'S') || (c1[i] == 'S' && c2[i] == 'P')){
			printf("Player1\n");
		}
		else if((c1[i] == 'P' && c2[i] == 'S') || (c1[i] == 'R' && c2[i] == 'P') || (c1[i] == 'S' && c2[i] == 'R')){
			printf("Player2\n");
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		input(i);
	}
	compete();
	return 0;
}
