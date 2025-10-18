// Problem:  Luogu P1150 Peter 的烟
// Link:     https://www.luogu.com.cn/problem/P1150
// Author:   nine19een
// Date:     2025-10-18

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, butt, cnt;

int main() {
    cin >> n >> k;
    while (n) {
        n--;
        cnt++;
        butt++;
        if (butt == k) {
            butt = 0;
            n++;
        }
    }
    cout << cnt;
    return 0;
}