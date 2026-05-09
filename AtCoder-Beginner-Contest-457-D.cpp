#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2e5 + 5;

int n;
ll k, a[maxn], ans;

bool check(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) {
            continue;
        }
        sum += (x - a[i] + i - 1) / i;
        if (sum > k) {
            return false;
        }
    }
    if (sum > k) {
        return false;
    } else {
        return true;
    }
}

void Binary() {
    ll l = 0, r = a[1] + k + 1;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ans = l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    };
    Binary();
    cout << ans;
    return 0;
}