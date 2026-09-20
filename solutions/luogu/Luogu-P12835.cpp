// Problem:  Luogu P12835 [蓝桥杯 2025 国 B] 蓝桥星数字
// Link:     https://www.luogu.com.cn/problem/P12835
// Author:   nine19een
// Date:     2026-06-04

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int len = 2, ans[20];
ll n, pow5[20];

void init() {
    pow5[0] = 1;
    for (int i = 1; i < 20; i++) {
        pow5[i] = pow5[i - 1] * 5;
    }
}

void findLen() {
    for (int i = 2; i <= 17; ++i) {
        if (n > 9 * pow5[i - 1]) {
            len++;
            n -= 9 * pow5[i - 1];
        } else {
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    findLen();
    for (int i = 1; i <= len; ++i) {
        int rem = len - i;
        if (i == 1) {
            for (int j = 1; j <= 9; ++j) {
                if (n > pow5[rem]) {
                    n -= pow5[rem];
                } else {
                    ans[i] = j;
                    break;
                }
            }
        } else {
            int start = ans[i - 1] & 1 ? 0 : 1;
            for (int j = start; j <= 9; j += 2) {
                if (n > pow5[rem]) {
                    n -= pow5[rem];
                } else {
                    ans[i] = j;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= len; ++i) {
        cout << ans[i];
    }
    return 0;
}
