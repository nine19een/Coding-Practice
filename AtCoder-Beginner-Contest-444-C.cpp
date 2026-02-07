// Problem:  AtCoder Beginner Contest 444 C - AtCoder Riko
// Link:     https://atcoder.jp/contests/abc444/tasks/abc444_c
// Author:   nine19een
// Date:     2026-02-07

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

int n;
vector<int> a, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (n & 1) {
        cout << a.back();
    } else {
        int idx = 0;
        int L = a.back();
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != L) {
                idx = i;
                break;
            }
        }
        //		cout << "idx=" << idx << '\n';
        if (idx == 0) {
            cout << a.back() << " " << a.back() * 2;
            return 0;
        }
        if (idx == n - 2) {
            cout << a.front() + a.back();
            return 0;
        }
        if (n / 2 - 1 == idx) {
            if (!(idx & 1)) {
                cout << a.front() + a.back();
                return 0;
            }
            if (a[0] == a[idx]) {
                cout << a.back() << " " << a.front() + a.back();
            } else {
                cout << a.back();
            }
            return 0;
        } else {
            cout << a.back();
            return 0;
        }
    }
    return 0;
}
