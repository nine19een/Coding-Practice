// Problem:  Luogu P1496 火烧赤壁
// Link:     https://www.luogu.com.cn/problem/P1496
// Author:   nine19een
// Date:     2025-11-25
// Method:   离散化+差分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn = 4e4 + 5;

struct Boat {
    ll l, r;
};

int n;
vector<ll> dis, diff(maxn, 0);
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dis.reserve(maxn);
    cin >> n;
    vector<Boat> boats(n);
    for (int i = 0; i < n; i++) {
        cin >> boats[i].l >> boats[i].r;
        dis.push_back(boats[i].l);
        dis.push_back(boats[i].r);
    }
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    for (int i = 0; i < n; i++) {
        int curL = lower_bound(dis.begin(), dis.end(), boats[i].l) - dis.begin();
        int curR = lower_bound(dis.begin(), dis.end(), boats[i].r) - dis.begin();
        diff[curL]++;
        diff[curR]--;
    }
    ll size = dis.size();
    for (ll i = 0; i < size - 1; i++) {
        if (i) {
            diff[i] += diff[i - 1];
        }
        if (diff[i]) {
            ans += dis[i + 1] - dis[i];
        }
    }
    cout << ans;
    return 0;
}
