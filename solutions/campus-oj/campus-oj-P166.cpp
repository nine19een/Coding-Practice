// Campus OJ P166 赛前讲义
// https://oj.nine19een.com/#library/P166

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2005;

struct Task {
    ll p, d;
};

int n, q;
vector<Task> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    v.reserve(maxn);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        ll p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }
    sort(v.begin(), v.end(), [](const Task &a, const Task &b) {
        return a.d < b.d;
    });
    priority_queue<ll> pq;
    ll sum = 0;
    for (auto t: v) {
        pq.push(t.p);
        sum += t.p;
        ll cnt = pq.size();
        ll tot = sum + (cnt - 1) / q;
        if (tot > t.d) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size();
    return 0;
}
