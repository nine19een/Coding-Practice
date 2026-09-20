// Problem:  Luogu B2166 查找不重复元素出现的位置
// Link:     https://www.luogu.com.cn/problem/B2166
// Author:   nine19een
// Date:     2025-11-19

#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (it != a.end() && *it == num) {
            cout << it - a.begin() + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
