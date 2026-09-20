// Problem:  Luogu P1321 单词覆盖还原
// Link:     https://www.luogu.com.cn/problem/P1321
// Author:   nine19een
// Date:     2025-10-24

#include <stdio.h>

int cnt_boy, cnt_girl;
char s[260];

void Match(int idx){
	if(s[idx] == 'b' || s[idx + 1] == 'o' || s[idx + 2] == 'y'){
		cnt_boy++;
	}
	if(s[idx] == 'g' || s[idx + 1] == 'i' || s[idx + 2] == 'r' || s[idx + 3] == 'l'){
		cnt_girl++;
	}
}

int main(){
	scanf("%s", s);
	for(int i = 0; i < 260; ++i){
		if(s[i] == 0){
			break;
		}
		Match(i);
	}
	printf("%d\n%d", cnt_boy, cnt_girl);
	return 0;
}
