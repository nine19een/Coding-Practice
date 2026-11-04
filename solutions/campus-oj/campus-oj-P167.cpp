// Campus OJ P167 Campus OJ 的评测进度
// https://oj.nine19een.com/#library/P167

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 1e5 + 5, inf = 1e18;

int n, k;
ll a[maxn], p[maxn];

bool ck(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > x) {
            continue;
        }
        sum += (x - a[i]) / p[i] + 1;
        if (sum >= k) {
            return true;
        }
    }
    return false;
}

void Binary() {
    ll l = 0, r = inf;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (ck(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i];
    }
    Binary();
    return 0;
}
