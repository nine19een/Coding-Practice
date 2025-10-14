// Problem:  Luogu P1025 [NOIP 2001 提高组] 数的划分
// Link:     https://www.luogu.com.cn/problem/P1025
// Author:   nine19een
// Date:     2025-10-15

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans;
int n, k;

void DFS(int idx, int remain, int last) {
    if (idx == k) {
        ans++;
        return;
    }
    for (int i = last; i <= remain; ++i) {
        if (2 * i > remain) {
            break;
        }
        DFS(idx + 1, remain - i, i);
    }
}

int main() {
    cin >> n >> k;
    DFS(1, n, 1);
    cout << ans << endl;
    return 0;
}