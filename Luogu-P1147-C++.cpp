// Problem:  Luogu P1147 连续自然数和
// Link:     https://www.luogu.com.cn/problem/P1147
// Author:   nine19een
// Date:     2025-11-23

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 2e6 + 5;

struct Prefix {
    ll val, idx;
};

ll n, a[maxn];
vector<Prefix> prefix;

int main() {
    prefix.reserve(maxn);
    cin >> n;
    prefix.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        Prefix num = {a[i] + prefix[i - 1].val, i};
        prefix.push_back(num);
    }
    for (auto it = prefix.begin(); it != prev(prefix.end()); it++) {
        ll aim_num = n + it->val;
        Prefix comp = {aim_num, 0};
        auto It = lower_bound(it, prefix.end(), comp, [](Prefix const &a, Prefix const &b) {
            return a.val < b.val;
        });
        if (It != prefix.end() && It->val == aim_num && It->idx != n) {
            cout << (it->idx + 1) << " " << (It->idx) << endl;
        }
    }
    return 0;
}