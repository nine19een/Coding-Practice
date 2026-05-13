// Problem:  Luogu P8306 【模板】字典树
// Link:     https://www.luogu.com.cn/problem/P8306
// Author:   nine19een
// Date:     2026-01-26

#include <bits/stdc++.h>
using namespace std;
const int maxLen = 3e6 + 5;

int t, trie[maxLen][80], pre[maxLen];

void Insert(string &s, int &idx) {
    int p = 0;
    for (char c: s) {
        int v = c - '0';
        if (!trie[p][v]) {
            trie[p][v] = ++idx;
            memset(trie[idx], 0, sizeof(trie[idx]));
            pre[idx] = 0;
        }
        p = trie[p][v];
        pre[p]++;
    }
}

int Query(string &s) {
    int p = 0;
    for (char c: s) {
        int v = c - '0';
        if (!trie[p][v]) {
            return 0;
        }
        p = trie[p][v];
    }
    return pre[p];
}

void op() {
    int n, q;
    cin >> n >> q;
    int idx = 0;
    memset(trie[0], 0, sizeof(trie[0]));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        Insert(s, idx);
    }
    for (int i = 1; i <= q; ++i) {
        string s;
        cin >> s;
        cout << Query(s) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
