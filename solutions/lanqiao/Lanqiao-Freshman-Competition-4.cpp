// Problem:  【蓝桥新生编程排位赛】 代码纪元
// Link:     https://www.lanqiao.cn/problems/21028/learning/?contest_id=262
// Author:   nine19een
// Date:     2025-10-10

#include<bits/stdc++.h>
using namespace std;

string s, s_re;

int main(){
	cin >> s;
	s_re = s;
	reverse(s_re.begin(), s_re.end());
	string t = max(s, s_re);
	t += 'a';
	cout << t;
	return 0;
}
