// Problem:  Luogu P1838 三子棋I
// Link:     https://www.luogu.com.cn/problem/P1838
// Author:   nine19een
// Date:     2025-11-22

#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> xiaoa;
int cnt_row1, cnt_row2, cnt_row3, cnt_column1, cnt_column2, cnt_column3, cnt_diagonal1, cnt_diagonal2;

int main() {
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (!(i & 1)) {
            xiaoa.push_back(s[i] - '0');
        }
    }
    for (int p: xiaoa) {
        if ((p - 1) / 3 == 0) {
            cnt_row1++;
        } else if ((p - 1) / 3 == 1) {
            cnt_row2++;
        } else if ((p - 1) / 3 == 2) {
            cnt_row3++;
        }
        if (p % 3 == 1) {
            cnt_column1++;
        } else if (p % 3 == 2) {
            cnt_column2++;
        } else if (p % 3 == 0) {
            cnt_column3++;
        }
        if (p == 1 || p == 9) {
            cnt_diagonal1++;
        } else if (p == 3 || p == 7) {
            cnt_diagonal2++;
        } else if (p == 5) {
            cnt_diagonal1++;
            cnt_diagonal2++;
        }
    }
    if (cnt_row1 == 3 || cnt_row2 == 3 || cnt_row3 == 3 || cnt_column1 == 3 || cnt_column2 == 3 || cnt_column3 == 3 || cnt_diagonal1 == 3 || cnt_diagonal2 == 3) {
        cout << "xiaoa wins.";
    } else if (!cnt_row1 || !cnt_row2 || !cnt_row3 || !cnt_column1 || !cnt_column2 || !cnt_column3 || !cnt_diagonal1 || !cnt_diagonal2) {
        cout << "uim wins.";
    } else {
        cout << "drew.";
    }
    return 0;
}
