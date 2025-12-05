// Problem:  Codeforces Round 1068 C. Kanade's Perfect Multiples
// Link:     https://codeforces.com/contest/2173/problem/C
// Author:   nine19een
// Date:     2025-12-07

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

void op() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    set<ll> s;
    unordered_set<ll> us;
    for (int i = 1; i <= n; ++i) {
        ll num;
        cin >> num;
        s.insert(num);
        us.insert(num);
    }
    while (!s.empty()) {
        ll num = *s.begin();
        ans.push_back(num);
        for (ll i = num; i <= k; i += num) {
            if (!us.count(i)) {
                cout << -1 << '\n';
                return;
            } else {
                s.erase(i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (ll p: ans) {
        cout << p << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
    return 0;
}
