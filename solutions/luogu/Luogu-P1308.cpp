// Problem:  Luogu P1308 [NOIP 2011 普及组] 统计单词数
// Link:     https://www.luogu.com.cn/problem/P1308
// Author:   nine19een
// Date:     2025-07-11

#include<bits/stdc++.h>
using namespace std;
char word[15], sen[100005], words[100005][15];
int count_ = 0, wc = 0;
int main()
{
	memset(sen, '\0', 100005);
	memset(word, '\0', 15);
	cin >> word;
	cin.get();
	cin.getline(sen,100005);
	int len_w = strlen(word);
	for(int i = 0; i < len_w; i++)
		if(word[i] <= 'Z' && word[i] >= 'A')
			word[i] += 32;
	int len_s = strlen(sen);
	for(int i = 0; i < len_s; i++)
		if(sen[i] <= 'Z' && sen[i] >= 'A')
			sen[i] += 32;
	int spc = 0;
	int c = len_s - 1;
	while(c >= 0){
		if(sen[c] != ' ')
			break;
		else if(sen[c] == ' '){
			spc++;
			c--;
		}
	}

	int idx = 0;
	for(int i = 0; i < len_s - spc ; i++)
	{
		if(sen[i] <= 'z' && sen[i] >= 'a')
			words[wc][idx++] = sen[i];
		else
		{
			if(idx > 0)
			{
				words[wc][idx] = '\0';
				wc++;
				idx = 0;
			}
		}
	}
	int first = -1, i = 0;
	int k = 0;

	for(i; i <= wc ; i++){
		bool match = true;
		int len = strlen(words[i]);
		while(sen[k] == ' ')
			k++;
			int q = 0;
		for(int p = 0; p < len; p++){
			if(words[i][p] != word[p]){
				match = false;
				break;
			}
			if((words[i][p] == '\0' && word[p] != '\0') || (words[i][p] != '\0' && word[p] == '\0'))
				match = false;
		}
		if(match){
			count_++;
			if(first == -1)
				first = k;
		}
		k += len;
	}
		if(first == -1)
			cout << first;
		else
			cout << count_ << " " << first;
		return 0;
}

//------------------------------------------------------------------------------------------------------------
// Date:     2025-11-10

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e6 + 5;

int ans_idx = INT_MAX, cnt;
char word[15], sentence[maxn];

void ToLower() {
    for (int i = 0; sentence[i] != 0; i++) {
        sentence[i] = tolower(sentence[i]);
    }
    for (int i = 0; word[i] != 0; i++) {
        word[i] = tolower(word[i]);
    }
}

bool match(int idx, int w) {
    for (int i = 0; i < w; i++) {
        if (word[i] != sentence[idx + i]) {
            return false;
        }
    }
    if (sentence[idx + w] != ' ' && sentence[idx + w] != 0) {
        return false;
    }
    return true;
}

void solve() {
    int w_len = strlen(word), s_len = strlen(sentence);
    for (int i = 0; i < s_len; i++) {
        if (word[0] == sentence[i] && (i == 0 || sentence[i - 1] == ' ')) {
            if (match(i, w_len)) {
                cnt++;
                ans_idx = min(i, ans_idx);
            }
        }
    }
}

int main() {
    cin >> word;
    getchar();
    cin.getline(sentence, maxn);
    ToLower();
    solve();
    if (ans_idx == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << cnt << " " << ans_idx;
    return 0;
}