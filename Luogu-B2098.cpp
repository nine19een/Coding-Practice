// Luogu B2098 - 整数去重
// https://www.luogu.com.cn/problem/B2098

#include <bits/stdc++.h>
using namespace std;

int n, vis[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (!vis[num]) {
            cout << num << " ";
            vis[num] = 1;
        }
    }
    return 0;
}