// Problem:  Luogu P1420 最长连号
// Link:     https://www.luogu.com.cn/problem/P1420
// Author:   nine19een
// Date:     2025-11-20

#include<bits/stdc++.h>
using namespace std;

int cnt, ans = INT_MIN, n, pre, num;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        if (num == pre + 1) {
            ans = max(ans, ++cnt);
            pre++;
        } else {
            cnt = 1;
            pre = num;
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}