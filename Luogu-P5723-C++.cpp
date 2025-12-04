// Problem:  Luogu P5723 【深基4.例13】质数口袋
// Link:     https://www.luogu.com.cn/problem/P5723
// Author:   nine19een
// Date:     2025-12-04

#include<bits/stdc++.h>
using namespace std;

int l, sum;
vector<int> pocket;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / i; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l;
    for (int i = 2;; ++i) {
        if (isPrime(i)) {
            sum += i;
            if (sum > l) {
                for (int p : pocket) {
                    cout << p << '\n';
                }
                cout << pocket.size();
                return 0;
            }
            pocket.push_back(i);
        }
    }
}