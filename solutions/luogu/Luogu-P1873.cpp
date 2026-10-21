// Luogu P1873 [COCI 2011/2012 #5] EKO / 砍树
// https://www.luogu.com.cn/problem/P1873

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 5;

ll n, m, wood[maxn];

bool check(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += wood[i] >= x ? wood[i] - x : 0;
    }
    return sum >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> wood[i];
    }
    sort(wood + 1, wood + n + 1);
    ll l = 1, r = 4e5 + 1;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1;
    return 0;
}