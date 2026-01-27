// Problem:  Luogu P3369 【模板】普通平衡树
// Link:     https://www.luogu.com.cn/problem/P3369
// Author:   nine19een
// Date:     2026-01-27

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.6e6, offset = 1e7;

int n, idx, trie[maxn][2], cnt[maxn];

void Insert(int x) {
    int p = 0;
    for (int i = 25; i >= 0; --i) {
        int v = x >> i & 1;
        if (!trie[p][v]) {
            trie[p][v] = ++idx;
        }
        p = trie[p][v];
        cnt[p]++;
    }
}

void Delete(int x) {
    int p = 0;
    for (int i = 25; i >= 0; --i) {
        int v = x >> i & 1;
        p = trie[p][v];
        cnt[p]--;
    }
}

int getRank(int x) {
    int p = 0, rank = 0;
    for (int i = 25; i >= 0; --i) {
        int v = x >> i & 1;
        if (v) {
            rank += cnt[trie[p][0]];
        }
        p = trie[p][v];
        if (!p) {
            break;
        }
    }
    return rank;
}

int getVal(int x) {
    int p = 0, val = 0;
    for (int i = 25; i >= 0; --i) {
        if (cnt[trie[p][0]] >= x) {
            p = trie[p][0];
        } else {
            x -= cnt[trie[p][0]];
            p = trie[p][1];
            val |= 1 << i;
        }
    }
    return val;
}

int getPrev(int x) {
    return getVal(getRank(x));
}

int getNext(int x) {
    return getVal(getRank(x + 1) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            Insert(x + offset);
        } else if (op == 2) {
            Delete(x + offset);
        } else if (op == 3) {
            cout << getRank(x + offset) + 1 << '\n';
        } else if (op == 4) {
            cout << getVal(x) - offset << '\n';
        } else if (op == 5) {
            cout << getPrev(x + offset) - offset << '\n';
        } else {
            cout << getNext(x + offset) - offset << '\n';
        }
    }
    return 0;
}
