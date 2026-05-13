// Problem:  P1088 [NOIP 2004 普及组] 火星人
// Link:     https://www.luogu.com.cn/problem/P1088
// Author:   nine19een
// Date:     2025-12-09
// Method:   全排列函数next_permutation

#include<bits/stdc++.h>
using namespace std;

int n, add_times;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> add_times;
    vector<int> finger(n);
    for (int i = 0; i < n; i++) {
        cin >> finger[i];
    }
    while (add_times--) {
        next_permutation(finger.begin(), finger.end());
    }
    for (int p: finger) {
        cout << p << " ";
    }
    return 0;
}
