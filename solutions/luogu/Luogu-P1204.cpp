// Problem:  Luogu P1204 [USACO1.2] 挤牛奶 Milking Cows
// Link:     https://www.luogu.com.cn/problem/P1204
// Author:   nine19een
// Date:     2025-11-27

#include<bits/stdc++.h>
using namespace std;
const int maxlr = 1e6 + 5;

int n, diff[maxlr], max_atleast1, max_none, min_l = INT_MAX, max_r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        min_l = min(l, min_l);
        max_r = max(r, max_r);
        diff[l]++;
        diff[r]--;
    }
    int atleast1 = 0, none = 0;
    for (int i = min_l; i < max_r; i++) {
        diff[i] += diff[i - 1];
        if (!diff[i]) {
            none++;
            max_atleast1 = max(max_atleast1, atleast1);
            atleast1 = 0;
        } else {
            atleast1++;
            max_none = max(max_none, none);
            none = 0;
        }
    }
    max_atleast1 = max(max_atleast1, atleast1);
    max_none = max(max_none, none);
    cout << max_atleast1 << " " << max_none;
    return 0;
}
