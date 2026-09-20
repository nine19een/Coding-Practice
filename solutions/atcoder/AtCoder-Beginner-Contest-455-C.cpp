// Problem:  AtCoder Beginner Contest 455 C - Vanish
// Link:     https://atcoder.jp/contests/abc455/tasks/abc455_c
// Author:   nine19een
// Date:     2026-04-25

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 3e5 + 5;

int n, k;
ll tot2;
unordered_map<int, int> mp;
vector<ll> sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sum.reserve(maxn);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        tot2 += a;
        mp[a]++;
    }
    for (pair<int, int> p: mp) {
        sum.push_back(1ll * p.first * p.second);
    }
    sort(sum.begin(), sum.end(), [](const ll &x, const ll &y) {
        return x > y;
    });
    k = min(k, (int) mp.size());
    for (int i = 0; i < k; i++) {
        tot2 -= sum[i];
    }
    cout << tot2;
    return 0;
}
