// Problem:  AtCoder Beginner Contest 449 C - Comfortable Distance
// Link:     https://atcoder.jp/contests/abc449/tasks/abc449_c
// Author:   nine19een
// Date:     2026-03-14

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 5e5 + 5;

int n, L, R;
ll ans;
vector<int> pos[30];
string s;

ll CNT(vector<int> &p, int val) {
    int len = (int) p.size();
    ll cnt = 0;
    int r = 0;
    for (int l = 0; l < len; l++) {
        if (r < l + 1) {
            r = l + 1;
        }
        while (r < len && p[r] - p[l] <= val) {
            r++;
        }
        cnt += r - l - 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> L >> R >> s;
    int idx = 1;
    for (char c: s) {
        pos[c - 'a' + 1].push_back(idx++);
    }
    for (int i = 1; i <= 26; i++) {
        ans += CNT(pos[i], R) - CNT(pos[i], L - 1);
    }
    cout << ans;
    return 0;
}
