// Problem:  Luogu B2137 判决素数个数
// Link:     https://www.luogu.com.cn/problem/B2137
// Author:   nine19een
// Date:     2025-12-03

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1100005;

int x, y, ans_pre[MAXN];
bool not_Prime[MAXN];
vector<int> primes;

int main() {
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    for (int i = 2; i <= y; ++i) {
        if (!not_Prime[i]) {
            primes.push_back(i);
        }
        ans_pre[i] = ans_pre[i - 1] + !not_Prime[i];
        for (int p : primes) {
            if (p * i > y) {
                break;
            }
            not_Prime[p * i] = true;
            if (i % p == 0) {
                break;
            }
        }
    }
    cout << ans_pre[y] - ans_pre[x - 1];
    return 0;
}