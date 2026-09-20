// Problem:  AtCoder Beginner Contest 444 D - Many Repunit Sum
// Link:     https://atcoder.jp/contests/abc444/tasks/abc444_d
// Author:   nine19een
// Date:     2026-02-19

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;

int n, max_idx;
vector<int> diff(maxn), b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int idx;
        cin >> idx;
        max_idx = max(max_idx, idx);
        diff[1]++;
        diff[idx + 1]--;
    }
    for (int i = 1; i <= max_idx; ++i) {
        diff[i] += diff[i - 1];
    }
    diff[max_idx + 1] = 0;
    int idx = 1;
    while (diff[idx]) {
        if (diff[idx] < 10) {
            b.push_back(diff[idx]);
        } else {
            b.push_back(diff[idx] % 10);
            diff[idx + 1] += diff[idx] / 10;
        }
        idx++;
    }
    for (auto it = prev(b.end());; it--) {
        cout << *it;
        if (it == b.begin()) {
            break;
        }
    }
    return 0;
}
