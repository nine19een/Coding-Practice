// Problem:  AtCoder Beginner Contest 440 E - Cookies
// Link:     https://atcoder.jp/contests/abc440/tasks/abc440_e
// Author:   nine19een
// Date:     2026-01-13

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, x;

struct Cookie {
    ll sum, last_idx, cnt;
};

struct cmp {
    bool operator()(const Cookie &c1, const Cookie &c2) {
        return c1.sum > c2.sum;
    }
};

void findCookies(vector<ll> &a, vector<ll> &d) {
    priority_queue<Cookie, vector<Cookie>, cmp> pq;
    ll max_val = a[0] * k;
    cout << max_val << '\n';
    int max_idx = n - 2;
    pq.push({d[0], 0, 1});
    int cnt_cookie = 2;
    while (cnt_cookie <= x) {
        auto top = pq.top();
        pq.pop();
        cout << max_val - top.sum << '\n';
        cnt_cookie++;
        if (top.last_idx < max_idx) {
            pq.push({top.sum - d[top.last_idx] + d[top.last_idx + 1], top.last_idx + 1, top.cnt});
        }
        if (top.cnt < k) {
            pq.push({top.sum + d[top.last_idx], top.last_idx, top.cnt + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] * k;
        return 0;
    }
    vector<ll> d(n - 1);
    sort(a.begin(), a.end(), greater<>());
    ll max_a = a[0];
    for (int i = 1; i < n; i++) {
        d[i - 1] = max_a - a[i];
    }
    findCookies(a, d);
    return 0;
}
