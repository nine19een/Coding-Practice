// Campus OJ P164 连续出勤
// https://oj.nine19een.com/#library/P164

#include<bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    char cur = '0';
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && cur == '0') {
            cnt++;
        }
        cur = s[i];
    }
    cout << cnt;
    return 0;
}
