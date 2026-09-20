// Problem:  AtCoder Beginner Contest 462 D - Accomplice
// Link:     https://atcoder.jp/contests/abc462/tasks/abc462_d
// Author:   nine19een
// Date:     2026-06-13

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

struct suspect {
    ll s, t;

    bool operator>(const suspect &other) const {
        return t > other.t;
    }
};

vector<suspect> sus;
priority_queue<suspect, vector<suspect>, greater<> > pq;

ll n, d, max_t, ans;

ll C(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sus.reserve(maxn);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        ll ns, nt;
        cin >> ns >> nt;
        sus.push_back({ns, nt});
        max_t = max(max_t, nt);
    }
    sort(sus.begin(), sus.end(), [](const suspect &a, const suspect &b) {
        return a.s < b.s;
    });
    ll cs = 1, ct = 1 + d;
    int sus_idx = 0;
    while (ct <= max_t) {
        while (sus_idx < sus.size() && sus[sus_idx].s <= cs) {
            if (sus[sus_idx].t < ct) {
                sus_idx++;
                continue;
            }
            pq.push(sus[sus_idx]);
            sus_idx++;
        }
        while (!pq.empty() && pq.top().t < ct) {
            pq.pop();
        }
        if (sus_idx == sus.size() && pq.size() <= 1) {
            break;
        }
        ans += C(static_cast<ll>(pq.size()));
        cs++;
        ct++;
    }
    cout << ans;
    return 0;
}
