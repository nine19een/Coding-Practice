// Problem:  Luogu P13894 [蓝桥杯 2023 省 C] 填充
// Link:     https://www.luogu.com.cn/problem/P13894
// Author:   nine19een
// Date:     2025-09-09

#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e6 + 5;
int cnt;
string str;
bool visited[maxn];

void Fill(string& s, int len){
	for(int i = 0; i < len; ++i){
		if(s[i] != '?'){
			if(!visited[i]){
				if(s[i] == s[i + 1]){
					cnt++;
					visited[i] = true;
					visited[i + 1] = true;
				}
				else if(s[i] != s[i + 1] && s[i + 1] != '?'){
					visited[i] = true;
				}
				else if(s[i] != s[i + 1] && s[i + 1] == '?'){
					cnt++;
					visited[i] = true;
					visited[i + 1] = true;
				}
			}
		}
		else{
			if(!visited[i]){
				cnt++;
				visited[i] = true;
				visited[i + 1] = true;
			}
		}
	}
	if(!visited[len]){
		if(s[len + 1] == '?' || s[len] == s[len + 1]){
			cnt++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> str;
	int len = str.size();
	if(len == 1){
		cout << 0;
		return 0;
	}
	Fill(str, len - 1);
	cout << cnt;
	return 0;
}
