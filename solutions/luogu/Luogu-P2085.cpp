// Luogu P2085 - 最小函数值
// https://www.luogu.com.cn/problem/P2085

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e4 + 5;

struct Num {
    ll val, id;
    int x;

    bool operator > (const Num &other) const {
        return val > other.val;
    }
};

int n, m, a[maxn], b[maxn], c[maxn];
Num f[maxn];
priority_queue<Num, vector<Num>, greater<Num>> pq;

ll F(int A, int B, int C, int x) {
    return A * x * x + B * x + C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        pq.push(Num{F(a[i], b[i], c[i], 1), i, 1});
    }
    int cnt = 0;
    while (!pq.empty()) {
        Num t = pq.top();
        pq.pop();
        cout << t.val << " ";
        cnt++;
        if (cnt == m) {
            break;
        }
        pq.push(Num{F(a[t.id], b[t.id], c[t.id], t.x + 1), t.id, t.x + 1});
    }
    return 0;
}