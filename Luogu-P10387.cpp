// Problem:  Luogu P10387 [蓝桥杯 2024 省 A] 训练士兵
// Link:     https://www.luogu.com.cn/problem/P10387
// Author:   nine19een
// Date:     2025-09-21

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e5 + 5;

struct Soldier {
    ll p, c;
}soldier [maxn];

ll n, S, max_c, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> soldier[i].p >> soldier[i].c;
        max_c = max(max_c, soldier[i].c);
    }
    vector<int> idx(max_c);
    iota (idx.begin(), idx.end(), 1);
    auto it = lower_bound (idx.begin(), idx.end(), 0,
        [&](int k, int dummy_val) -> bool {
            ll sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += (soldier[i].c >= k) ? soldier[i].p : 0;
            }
            return S <= sum;
        }
    );
    if (it != idx.end()) {
        ans += S * ((*it) - 1);
        for (int i = 1; i <= n; i++) {
            if ((*it) <= soldier[i].c) {
                ans += (soldier[i].c - (*it) + 1) * soldier[i].p;
            }
        }
    }
    else {
        ans = S * max_c;
    }
    cout << ans;
    return 0;
}
