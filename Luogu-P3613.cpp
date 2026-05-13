// Problem:  Luogu P3613 【深基15.例2】寄包柜
// Link:     https://www.luogu.com.cn/problem/P3613
// Author:   nine19een
// Date:     2025-12-08

#include<bits/stdc++.h>
using namespace std;

int n, q;
unordered_map<int, unordered_map<int, int> > cabinet;

void store() {
    int i, j, k;
    cin >> i >> j >> k;
    cabinet[i][j] = k;
}

void query() {
    int i, j;
    cin >> i >> j;
    cout << cabinet[i][j] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            store();
        } else {
            query();
        }
    }
    return 0;
}
