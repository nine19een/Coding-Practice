// Problem:  Luogu P1012 [NOIP 1998 提高组] 拼数
// Link:     https://www.luogu.com.cn/problem/P1012
// Author:   nine19een
// Date:     2025-10-02
// Method:   手写冒泡排序

#include<bits/stdc++.h>
using namespace std;

int n;
char num[25][15];

int charTOint(char c) {
    return c - '0';
}

bool ifSwap(char right[], char left[]) {
    for (int i = 0; i < 9; i++) {
        if ((right[i] == 0 && left[i] != 0) || (right[i] != 0 && left[i] == 0)) {
            string r1 = right, l1 = left;
            string r2 = r1 + l1, l2 = l1 + r1;
            int len = r2.length();
            for (int j = 0; j < len; j++) {
                if (charTOint(r2[j]) > charTOint(l2[j])) {
                    return true;
                }
                else if (charTOint(r2[j]) < charTOint(l2[j])) {
                    return false;
                }
            }
        }
        else if (charTOint(right[i]) > charTOint(left[i])) {
            return true;
        }
        else if (charTOint(right[i]) < charTOint(left[i])) {
            return false;
        }
        else if (right[i] == 0 && left[i] == 0) {
            return false;
        }
    }
}

void bubbleSort() {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (ifSwap(num[j], num[j - 1])) {
                swap(num[j], num[j - 1]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    bubbleSort();
    for (int i = 0; i < n; i++) {
        cout << num[i];
    }
    return 0;
}
