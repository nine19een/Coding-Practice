// Problem:  AtCoder Beginner Contest 459 C - Drop Blocks
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_c
// Author:   nine19een
// Date:     2026-05-23

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

int n, q, a[maxn], c[maxn], base;

inline int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += val;
    }
}

int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    update(1, n);
    for (int i = 1; i <= q; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        if (num1 == 1) {
            update(a[num2] + 1, -1);
            a[num2]++;
            update(a[num2] + 1, 1);
            if (query(base + 1) - query(base) == 0) {
                base++;
            }
        } else {
            int pos = num2 + base;
            cout << (pos >= maxn ? 0 : n - query(pos)) << '\n';
        }
    }
}
