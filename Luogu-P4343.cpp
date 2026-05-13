// Problem:  Luogu P4343 [SHOI2015] 自动刷题机
// Link:     https://www.luogu.com.cn/problem/P4343
// Author:   nine19een
// Date:     2026-01-21

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxl = 1e5 + 5;

int L, k, Log[maxl];

int CNT(ll x) {
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= L; i++) {
        sum += Log[i];
        if (sum < 0) {
            sum = 0;
        } else {
            if (sum >= x) {
                cnt++;
                sum = 0;
            }
        }
    }
    return cnt;
}

ll findMin(ll cnt, ll max_cnt_code) {
    if (cnt == k) {
        return 1;
    }
    ll l = 1, r = max_cnt_code + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (CNT(mid) > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

ll findMax(ll cnt, ll max_cnt_code) {
    if (cnt == k) {
        return max_cnt_code;
    }
    ll l = 1, r = max_cnt_code + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (CNT(mid) < k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> k;
    ll max_cnt_code = 0, cnt_code = 0;
    for (int i = 1; i <= L; i++) {
        cin >> Log[i];
        cnt_code += Log[i];
        if (cnt_code < 0) {
            cnt_code = 0;
        }
        max_cnt_code = max(max_cnt_code, cnt_code);
    }
    ll cnt_1 = CNT(1), cnt_2 = CNT(max_cnt_code);
    if (cnt_1 < k || cnt_2 > k) {
        cout << -1;
        return 0;
    }
    ll ans_min = findMin(cnt_1, max_cnt_code), ans_max = findMax(cnt_2, max_cnt_code);
    if (ans_min > ans_max) {
        cout << -1;
        return 0;
    }
    cout << ans_min << " " << ans_max;
    return 0;
}
