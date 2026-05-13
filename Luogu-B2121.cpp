// Problem:  Luogu B2121 最长最短单词
// Link:     https://www.luogu.com.cn/problem/B2121
// Author:   nine19een
// Date:     2025-11-13

#include<bits/stdc++.h>
using namespace std;
int const maxn = 2e4 + 5, maxm = 205;

string word[maxm], sentence;
int len[maxm], min_len = INT_MAX, max_len = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sentence.reserve(maxn);
    getline(cin, sentence);
    int idx = 0;
    for (char c: sentence) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            word[idx] += c;
        } else {
            idx++;
        }
    }
    for (string s: word) {
        if (!s.length()) {
            continue;
        }
        min_len = min(min_len, (int) s.length());
        max_len = max(max_len, (int) s.length());
    }
    bool flag_min = false, flag_max = false;
    string ans_min, ans_max;
    for (string s: word) {
        if (s.length() == min_len && !flag_min) {
            ans_min = s;
            flag_min = true;
        }
        if (s.length() == max_len && !flag_max) {
            ans_max = s;
            flag_max = true;
        }
    }
    cout << ans_max << endl << ans_min;
    return 0;
}
