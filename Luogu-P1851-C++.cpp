// Problem:  Luogu P1851 好朋友
// Link:     https://www.luogu.com.cn/problem/P1851
// Author:   nine19een
// Date:     2025-11-29

#include<bits/stdc++.h>
using namespace std;

int factorSum(int x) {
    int sum = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int s;
    cin >> s;
    for (int i = s;; i++) {
        int sum = factorSum(i);
        if (factorSum(sum) == i && sum != i) {
            cout << i << " " << sum;
            return 0;
        }
    }
}