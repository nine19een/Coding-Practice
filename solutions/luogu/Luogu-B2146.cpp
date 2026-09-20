// Problem:  Luogu B2146 Hermite 多项式
// Link:     https://www.luogu.com.cn/problem/B2146
// Author:   nine19een
// Date:     2025-12-07

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x;

ll Hermite(int n, int x) {
    if (!n) {
        return 1;
    } else if (n == 1) {
        return 2 * x;
    } else if (n > 1) {
        return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
    }
}

int main() {
    cin >> n >> x;
    cout << Hermite(n, x);
    return 0;
}
