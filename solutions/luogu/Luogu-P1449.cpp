// Problem:  Luogu P1449 后缀表达式
// Link:     https://www.luogu.com.cn/problem/P1449
// Author:   nine19een
// Date:     2025-12-09

#include<bits/stdc++.h>
using namespace std;

string s;
stack<int> st;

int main() {
    cin >> s;
    string num_s;
    for (char c: s) {
        if (c >= '0' && c <= '9') {
            num_s += c;
        } else if (c == '.') {
            int num = stoi(num_s);
            num_s.clear();
            st.push(num);
        } else if (c == '+') {
            int num = st.top();
            st.pop();
            st.top() += num;
        } else if (c == '-') {
            int num = st.top();
            st.pop();
            st.top() -= num;
        } else if (c == '*') {
            int num = st.top();
            st.pop();
            st.top() *= num;
        } else if (c == '/') {
            int num = st.top();
            st.pop();
            st.top() /= num;
        }
    }
    cout << st.top();
    return 0;
}
