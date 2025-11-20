// Problem:  Luogu P1420 最长连号
// Link:     https://www.luogu.com.cn/problem/P1420
// Author:   nine19een
// Date:     2025-11-20

#include<bits/stdc++.h>
using namespace std;

int cnt, ans = INT_MIN, n, prev_num, num;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        if (num == prev_num + 1) {
            ans = max(ans, ++cnt);
            prev_num++;
        } else {
            cnt = 1;
            prev_num = num;
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}
