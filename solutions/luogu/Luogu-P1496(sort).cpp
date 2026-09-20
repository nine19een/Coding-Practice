// Problem:  Luogu P1496 火烧赤壁
// Link:     https://www.luogu.com.cn/problem/P1496
// Author:   nine19een
// Date:     2025-11-25
// Method:   排序合并区间

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Boat {
    ll l, r;
};

ll n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<Boat> boat(n);
    for (int i = 0; i < n; i++) {
        cin >> boat[i].l >> boat[i].r;
    }
    sort(boat.begin(), boat.end(), [](const Boat &a, const Boat &b) {
        if (a.l != b.l) {
            return a.l < b.l;
        } else {
            return a.r < b.r;
        }
    });
    ll L = boat.front().l, R = boat.front().r;
    for (auto it = next(boat.begin()); it != boat.end(); it++) {
        if (it->l <= R) {
            R = max(R, it->r);
        } else {
            ans += R - L;
            L = it->l;
            R = it->r;
        }
    }
    ans += R - L;
    cout << ans;
    return 0;
}
