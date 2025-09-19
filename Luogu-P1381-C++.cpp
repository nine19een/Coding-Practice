// Problem:  Luogu P1381 单词背诵
// Link:     https://www.luogu.com.cn/problem/P1381
// Author:   nine19een
// Date:     2025-08-20

#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 5;

int n, m, ans1 = 0, ans2 = maxn;
unordered_map<string, int>word_map;
vector<string>article;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	article.reserve(maxn);
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		word_map[s] = 1;
	}
	cin >> m;
	while(m--){
		string s;
		cin >> s;
		if(word_map.count(s) && word_map[s]){
			ans1++;
			word_map[s]--;
		}
		article.push_back(s);
	}
	if(ans1 == 0){
		cout << 0 << endl << 0;
		return 0;
	}
	int i = 0, j = 0, howMany = 0, len = 0;
	if(word_map.count(article[0])){
		len++;
		howMany++;
		word_map[article[0]]++;
		if(howMany == ans1){
			cout << 1 << endl << 1;
			return 0;
		}
	}
	else{
		len++;
	}
	int size = article.size();
	while(1){
		if(ans2 == ans1){
			break;
		}
		else if(howMany < ans1){
			i++;
			len++;
			if(i == size){
				break;
			}
			if(word_map.count(article[i])){
				if(!word_map[article[i]]){
					howMany++;
					if(howMany == ans1){
						ans2 = min(len, ans2);
					}
				}
				word_map[article[i]]++;
			}
		}
		else if(howMany == ans1){
			
			if(word_map.count(article[j])){
				
				if(word_map[article[j]] > 1){
					j++;
					len--;
					ans2 = min(ans2, len);
					word_map[article[j - 1]]--;
				}
				else{
					i++;
					len++;
					if(i == size){
						break;
					}
					if(word_map.count(article[i])){
						word_map[article[i]]++;
					}
				}
			}
			else{
				j++;
				len--;
				ans2 = min(ans2, len);
			}
		}
	}
	cout << ans1 << endl << ans2;
	return 0;
}
