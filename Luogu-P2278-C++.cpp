// Problem:  Luogu P2085 最小函数值
// Link:     https://www.luogu.com.cn/problem/P2085
// Author:   nine19een
// Date:     2026-01-14

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 5;

struct Function {
    ll f_num, x, val;
};

struct cmp {
    bool operator()(const Function &a, const Function &b) {
        return a.val > b.val;
    }
};

int n, m, a[maxn], b[maxn], c[maxn];

ll F(ll num, ll x) {
    return a[num] * x * x + b[num] * x + c[num];
}

void findMin() {
    priority_queue<Function, vector<Function>, cmp> pq;
    for (int i = 1; i <= n; i++) {
        pq.push({i, 1, a[i] + b[i] + c[i]});
    }
    int cnt = 1;
    while (cnt <= m) {
        auto t = pq.top();
        pq.pop();
        cout << t.val << " ";
        cnt++;
        pq.push({t.f_num, t.x + 1, F(t.f_num, t.x + 1)});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    findMin();
    return 0;
}
