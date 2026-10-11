// Luogu P1149 [NOIP 2008 提高组] 火柴棒等式
// https://www.luogu.com.cn/problem/P1149

#include <bits/stdc++.h>
using namespace std;

int n, cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans;

int Cost(int num) {
    int cnt = 0;
    if (!num) {
        return 6;
    }
    while (num) {
        cnt += cost[num % 10];
        num /= 10;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= 999; ++i) {
        for (int j = 0; j <= 999; ++j) {
            if (Cost(i) + Cost(j) + Cost(i + j) == n - 4) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
