// Problem:  AtCoder Beginner Contest 451 D - Concat Power of 2
// Link:     https://atcoder.jp/contests/abc451/tasks/abc451_d
// Author:   nine19een
// Date:     2026-03-28

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e9;

vector<ll> two = {
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
    1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912
};

vector<ll> ans;
unordered_set<ll> vis;

ll getLen(ll x) {
    ll len, base = 1;
    for (len = 1; len <= 10; len++) {
        if (x / base < 10) {
            break;
        }
        base *= 10;
    }
    return len;
}

ll time10(ll len) {
    ll ten = 1;
    while (len--) {
        ten *= 10;
    }
    return ten;
}

void DFS(ll cur) {
    if (vis.count(cur)) {
        return;
    }
    vis.insert(cur);
    ans.push_back(cur);
    for (ll x: two) {
        ll len = getLen(x);
        ll next2 = cur * time10(len) + x;
        if (next2 > maxn) {
            break;
        }
        DFS(next2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll x: two) {
        DFS(x);
    }
    sort(ans.begin(), ans.end());
    int n;
    cin >> n;
    cout << ans[n - 1];
    return 0;
}
