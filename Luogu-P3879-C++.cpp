// Problem:  Luogu
// Link:     https://www.luogu.com.cn/problem/P3879
// Author:   nine19een
// Date:     2025-08-19

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e9 + 7;
struct Word{
	char wd[25];
	int idx;
};
int N, M, L, search_hash;
vector<int>ans;
vector<Word>a[10000019];
char word[25] = {0}, search_word[25] = {0};
vector<string>sen;

int HASH(char w[]){
	ll hash = 0;
	for(int i = 0; i <= 25; ++i){
		if(w[i] == 0){
			break;
		}
		hash = (hash * 131 + w[i]) % maxn;
	}
	hash %= 10000019;
	return hash;
}

void Store(char w[], int idx){
	Word owo;
	strcpy(owo.wd, w);
	owo.idx = idx;
	a[HASH(w)].push_back(owo);
	return;
}

int main(){
	ans.reserve(100005);
	cin >> N;
	for(int i = 1; i <= N; ++i){
		cin >> L;
		for(int j = 1; j <= L; ++j){
			cin >> word;
			Store(word, i);
		}
	}
	cin >> M;
	for(int i = 1; i <= M; ++i){
		cin >> search_word;
		for(Word p : a[HASH(search_word)]){
			if(strcmp(p.wd, search_word) == 0){
				ans.push_back(p.idx);
			}
		}
		if(ans.empty()){
			cout << endl;
			continue;
		}
		else{
			sort(ans.begin(), ans.end());
			ans.erase(unique(ans.begin(), ans.end()), ans.end());
			int size = ans.size();
			for(int j = 0; j < size; ++j){
				if(j == size - 1){
					cout << ans[j];
				}
				else{
					cout << ans[j] << " ";
				}
			}
			if(i == M){
				break;
			}
			cout << endl;
		}
		ans.clear();
	}
	return 0;
} 
