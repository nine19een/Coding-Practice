// Problem:  Luogu P1160 队列安排
// Link:     https://www.luogu.com.cn/problem/P1160
// Author:   nine19een
// Date:     2026-01-20
// Method:   STL list

#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, list<int>::iterator> um;
list<int> l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    l.push_back(1);
    um[1] = l.begin();
    for (int i = 2; i <= n; ++i) {
        int k, p;
        cin >> k >> p;
        if (!p) {
            um[i] = l.insert(um[k], i);
        } else {
            um[i] = l.insert(next(um[k]), i);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        if (um[x] != l.end() && *um[x] == x) {
            um[x] = l.erase(um[x]);
        }
    }
    for (int p: l) {
        cout << p << " ";
    }
    return 0;
}
