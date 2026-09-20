// Problem:  Luogu B2133 我家的门牌号
// Link:     https://www.luogu.com.cn/problem/B2133
// Author:   nine19een
// Date:     2025-12-10

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1;; ++i) {
        sum += i;
        for (int j = 1; j <= i; ++j) {
            if (sum - 3 * j == n) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
}
