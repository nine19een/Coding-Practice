// Problem:  Luogu P1160 队列安排
// Link:     https://www.luogu.com.cn/problem/P1160
// Author:   nine19een
// Date:     2026-01-20
// Method:   手写数组模拟链表

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct Node {
    int l, r;
    bool is_delete;
};

int n, m;
Node lt[maxn];

void insertLeft(int k, int i) {
    lt[lt[k].l].r = i;
    lt[i].l = lt[k].l;
    lt[i].r = k;
    lt[k].l = i;
}

void insertRight(int k, int i) {
    lt[lt[k].r].l = i;
    lt[i].r = lt[k].r;
    lt[i].l = k;
    lt[k].r = i;
}

void Delete(int x, int &start) {
    if (lt[x].is_delete) {
        return;
    }
    lt[lt[x].l].r = lt[x].r;
    lt[lt[x].r].l = lt[x].l;
    if (!lt[x].l) {
        start = lt[x].r;
    }
    lt[x].is_delete = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    lt[1].l = 0, lt[1].r = 0;
    int start = 1;
    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        if (!p) {
            insertLeft(k, i);
        } else {
            insertRight(k, i);
        }
        if (!lt[i].l) {
            start = i;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        Delete(x, start);
    }
    int idx = start;
    while (idx) {
        cout << idx << " ";
        idx = lt[idx].r;
    }
    return 0;
}
