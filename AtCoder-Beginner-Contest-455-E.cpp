// Problem:  AtCoder Beginner Contest 455 E - Unbalanced ABC Substrings
// Link:     https://atcoder.jp/contests/abc455/tasks/abc455_e
// Author:   nine19een
// Date:     2026-04-26

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2e5 + 5, offset = 200005, base = 500005;

int n, preA[maxn], preB[maxn], preC[maxn];
ll tot, tot2, tot3;
string s;
unordered_map<int, ll> mpAB, mpBC, mpCA;
unordered_map<ll, ll> mpABC;

ll getKey(int x, int y) {
    return 1ll * (x + offset) * base + (y + offset);
}

void init() {
    mpAB[0] = 1;
    mpBC[0] = 1;
    mpCA[0] = 1;
    mpABC[getKey(0, 0)] = 1;
    tot = 1ll * n * (n + 1) / 2;
}

void cnt(int idx) {
    int d1 = preA[idx] - preB[idx];
    tot2 += mpAB[d1]++;
    int d2 = preB[idx] - preC[idx];
    tot2 += mpBC[d2]++;
    int d3 = preC[idx] - preA[idx];
    tot2 += mpCA[d3]++;
    tot3 += mpABC[getKey(d1, d2)]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    init();
    for (int i = 0; i < n; i++) {
        int idx = i + 1;
        preA[idx] = preA[i];
        preB[idx] = preB[i];
        preC[idx] = preC[i];
        if (s[i] == 'A') {
            preA[idx]++;
        } else if (s[i] == 'B') {
            preB[idx]++;
        } else {
            preC[idx]++;
        }
        cnt(idx);
    }
    cout << tot - tot2 + tot3 * 2;
    return 0;
}
