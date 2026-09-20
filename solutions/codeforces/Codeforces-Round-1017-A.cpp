// Problem:  Codeforces Round 1017 A. Trippi Troppi
// Link:     https://codeforces.com/contest/2094/problem/A
// Author:   nine19een
// Date:     2025-08-07

#include <bits/stdc++.h>
using namespace std;
int n;
struct Sentence{
	char a[15], b[15], c[15];
};
Sentence s[105];

int main(){
	memset(s, 0, sizeof(s));
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].b >> s[i].c;
	}
	for(int i = 1; i <= n; i++){
		cout << s[i].a[0] << s[i].b[0] << s[i].c[0] << endl;
	}
	return 0;
}
