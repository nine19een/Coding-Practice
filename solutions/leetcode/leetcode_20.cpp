// 20.有效的括号
// https://leetcode.cn/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            if ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};