// Problem:  Luogu B2119 删除单词后缀
// Link:     https://www.luogu.com.cn/problem/B2119
// Author:   nine19een
// Date:     2025-11-11

#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    auto end = s.end();
    auto last1 = prev(end);
    auto last2 = prev(last1);
    auto last3 = prev(last2);
    if((*last1 == 'y' && *last2 == 'l') || (*last1 == 'r' && *last2 == 'e')){
        for(int i = 1; i <= 2; ++i){
            s.pop_back();
        }
    }
    else if(*last1 == 'g' && *last2 == 'n' && *last3 == 'i'){
        for(int i = 1; i <= 3; ++i){
            s.pop_back();
        }
    }
    cout << s;
    return 0;
}